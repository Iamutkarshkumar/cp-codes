// Assignment 4: Implement a Genetic Algorithm to solve an optimization-based, path-planning problem. 
// Observe how mutation and crossover parameters affect performance.

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

struct Individual {
    vector<int> genes;    // sequence of node indices representing a path
    double fitness;
};

// Parameters
int POP_SIZE = 100;
int GENERATIONS = 500;
double MUTATION_RATE = 0.1;
double CROSSOVER_RATE = 0.8;

// Graph representation (adjacency list with weights)
int N; // number of nodes
vector<vector<pair<int,double>>> adj;
vector<pair<double,double>> coords; // for heuristic or visualization
int startNode, goalNode;

// Fitness: inverse of path cost (shorter = higher fitness)
double compute_path_cost(const vector<int>& path) {
    double cost = 0;
    for (int i = 1; i < path.size(); ++i) {
        int u = path[i-1], v = path[i];
        bool found = false;
        for (auto &e : adj[u]) if (e.first == v) { cost += e.second; found = true; break; }
        if (!found) return 1e9; // invalid edge
    }
    return cost;
}

void evaluate(vector<Individual>& pop) {
    for (auto &ind : pop) {
        double cost = compute_path_cost(ind.genes);
        ind.fitness = cost < 1e8 ? 1.0 / cost : 0;
    }
}

Individual tournament_select(const vector<Individual>& pop) {
    int k = 5;
    Individual best;
    best.fitness = -1;
    for (int i = 0; i < k; ++i) {
        const auto &c = pop[rand() % pop.size()];
        if (c.fitness > best.fitness) best = c;
    }
    return best;
}

vector<int> crossover(const vector<int>& a, const vector<int>& b) {
    int len = a.size();
    vector<int> child(len, -1);
    int cut1 = rand() % len, cut2 = rand() % len;
    if (cut1 > cut2) swap(cut1, cut2);
    unordered_set<int> taken;
    for (int i = cut1; i <= cut2; ++i) {
        child[i] = a[i]; taken.insert(a[i]);
    }
    int idx = 0;
    for (int i = 0; i < len; ++i) {
        if (child[i] == -1) {
            while (taken.count(b[idx])) idx++;
            child[i] = b[idx++];
        }
    }
    return child;
}

void mutate(vector<int>& genes) {
    if ((double)rand()/RAND_MAX < MUTATION_RATE) {
        int i = rand() % genes.size();
        int j = rand() % genes.size();
        swap(genes[i], genes[j]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));

    // Example: fully connected grid 10x10
    int R = 10, C = 10;
    N = R*C;
    startNode = 0;
    goalNode = N-1;
    adj.assign(N, {});
    coords.assign(N, {});
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
        int u = r*C + c;
        coords[u] = {r,c};
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto &d: dirs) {
            int nr = r+d.first, nc = c+d.second;
            if (nr>=0 && nr<R && nc>=0 && nc<C) {
                int v = nr*C + nc;
                adj[u].push_back({v, 1.0});
            }
        }
    }

    // Initialize population with random paths (simple greedy/random walks)
    vector<Individual> pop(POP_SIZE);
    for (auto &ind : pop) {
        ind.genes.clear();
        // naive initialization: random permutation of all nodes, start at 0, end at goal
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 0);
        random_shuffle(perm.begin()+1, perm.end());
        perm[0] = startNode;
        perm[N-1] = goalNode;
        ind.genes = perm;
    }

    evaluate(pop);

    // Evolution loop
    for (int gen = 0; gen < GENERATIONS; ++gen) {
        vector<Individual> newpop;
        while (newpop.size() < POP_SIZE) {
            Individual p1 = tournament_select(pop);
            Individual p2 = tournament_select(pop);
            vector<int> childGenes;
            if ((double)rand()/RAND_MAX < CROSSOVER_RATE) childGenes = crossover(p1.genes, p2.genes);
            else childGenes = p1.genes;
            mutate(childGenes);
            newpop.push_back({childGenes, 0});
        }
        evaluate(newpop);
        pop.swap(newpop);

        // Optional: log best fitness
        if (gen % 50 == 0) {
            double bestFit = 0;
            for (auto &ind : pop) bestFit = max(bestFit, ind.fitness);
            cout << "Gen " << gen << ": Best fitness = " << bestFit << "\n";
        }
    }

    // Output best path found
    auto best = max_element(pop.begin(), pop.end(), [](auto&a,auto&b){return a.fitness<b.fitness;});
    cout << "Best path cost: " << (1.0/best->fitness) << "\n";
    cout << "Path sequence: ";
    for (int node : best->genes) cout << node << " ";
    cout << "\n";

    return 0;
}
