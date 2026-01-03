// Assignment 5: Implement the Grey Wolf Optimization algorithm for an optimization problem, comparing 
// its performance with the Genetic Algorithm and analyzing its convergence behavior. 

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// Benchmark function: Sphere
// f(x) = sum(x_i^2), global minimum at (0,...,0) with f=0

double sphere(const vector<double>& x) {
    double sum = 0;
    for (double xi : x) sum += xi * xi;
    return sum;
}

//================ Genetic Algorithm ====================
struct GA {
    int pop_size;
    int dim;
    vector<pair<vector<double>, double>> population; // (solution, fitness)
    double crossover_rate, mutation_rate;
    double lower_bound, upper_bound;
    mt19937 gen;

    GA(int pop_size_, int dim_, double cr, double mr, double lb, double ub)
        : pop_size(pop_size_), dim(dim_), crossover_rate(cr), mutation_rate(mr), lower_bound(lb), upper_bound(ub) {
        gen.seed(random_device{}());
        init_population();
    }

    void init_population() {
        uniform_real_distribution<double> dist(lower_bound, upper_bound);
        population.clear();
        for (int i = 0; i < pop_size; ++i) {
            vector<double> sol(dim);
            for (int j = 0; j < dim; ++j) sol[j] = dist(gen);
            population.emplace_back(sol, sphere(sol));
        }
    }

    vector<double> tournament_select() {
        uniform_int_distribution<int> dist(0, pop_size - 1);
        auto best = population[dist(gen)];
        for (int i = 1; i < 3; ++i) {
            auto cand = population[dist(gen)];
            if (cand.second < best.second) best = cand;
        }
        return best.first;
    }

    vector<double> crossover(const vector<double>& a, const vector<double>& b) {
        uniform_real_distribution<double> dist(0.0, 1.0);
        vector<double> child(dim);
        for (int i = 0; i < dim; ++i) {
            child[i] = (dist(gen) < 0.5) ? a[i] : b[i];
        }
        return child;
    }

    void mutate(vector<double>& sol) {
        uniform_real_distribution<double> dist(0.0, 1.0);
        uniform_real_distribution<double> val_dist(lower_bound, upper_bound);
        for (int i = 0; i < dim; ++i) {
            if (dist(gen) < mutation_rate) sol[i] = val_dist(gen);
        }
    }

    double run_step() {
        vector<pair<vector<double>, double>> newpop;
        uniform_real_distribution<double> dist(0.0, 1.0);
        while (newpop.size() < pop_size) {
            auto p1 = tournament_select();
            auto p2 = tournament_select();
            vector<double> child = (dist(gen) < crossover_rate) ? crossover(p1, p2) : p1;
            mutate(child);
            double fit = sphere(child);
            newpop.emplace_back(child, fit);
        }
        population.swap(newpop);
        // return best fitness
        double best = population[0].second;
        for (auto &ind : population) best = min(best, ind.second);
        return best;
    }
};

//=============== Grey Wolf Optimizer ====================
struct GWO {
    int pack_size;
    int dim;
    int max_iter;
    double lb, ub;
    vector<vector<double>> positions;
    vector<double> fitness;
    mt19937 gen;

    GWO(int pack_size_, int dim_, int max_iter_, double lb_, double ub_)
        : pack_size(pack_size_), dim(dim_), max_iter(max_iter_), lb(lb_), ub(ub_) {
        gen.seed(random_device{}());
        init_pack();
    }

    void init_pack() {
        positions.resize(pack_size, vector<double>(dim));
        fitness.resize(pack_size);
        uniform_real_distribution<double> dist(lb, ub);
        for (int i = 0; i < pack_size; ++i) {
            for (int j = 0; j < dim; ++j) positions[i][j] = dist(gen);
            fitness[i] = sphere(positions[i]);
        }
    }

    double run_step(int iter) {
        // identify alpha (best), beta, delta
        vector<int> idx(pack_size);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return fitness[a] < fitness[b]; });
        auto alpha_pos = positions[idx[0]];
        auto beta_pos  = positions[idx[1]];
        auto delta_pos = positions[idx[2]];

        double a_coef = 2.0 * (1.0 - double(iter) / max_iter);
        uniform_real_distribution<double> dist01(0.0, 1.0);

        for (int i = 0; i < pack_size; ++i) {
            for (int j = 0; j < dim; ++j) {
                double r1 = dist01(gen), r2 = dist01(gen);
                double A1 = 2*a_coef*r1 - a_coef;
                double C1 = 2*r2;
                double D_alpha = fabs(C1*alpha_pos[j] - positions[i][j]);
                double X1 = alpha_pos[j] - A1 * D_alpha;

                r1 = dist01(gen); r2 = dist01(gen);
                double A2 = 2*a_coef*r1 - a_coef;
                double C2 = 2*r2;
                double D_beta = fabs(C2*beta_pos[j] - positions[i][j]);
                double X2 = beta_pos[j] - A2 * D_beta;

                r1 = dist01(gen); r2 = dist01(gen);
                double A3 = 2*a_coef*r1 - a_coef;
                double C3 = 2*r2;
                double D_delta = fabs(C3*delta_pos[j] - positions[i][j]);
                double X3 = delta_pos[j] - A3 * D_delta;

                positions[i][j] = (X1 + X2 + X3) / 3.0;
                // boundary
                positions[i][j] = min(max(positions[i][j], lb), ub);
            }
            fitness[i] = sphere(positions[i]);
        }
        return fitness[idx[0]]; // best fitness
    }
};

int main() {
    // Problem settings
    int dim = 30;
    double lb = -100, ub = 100;
    int iterations = 200;

    // GA parameters
    GA ga(50, dim, 0.9, 0.1, lb, ub);
    // GWO parameters
    GWO gwo(50, dim, iterations, lb, ub);

    cout << "Iter,GA_best,GWO_best\n";
    for (int iter = 1; iter <= iterations; ++iter) {
        double ga_best = ga.run_step();
        double gwo_best = gwo.run_step(iter);
        cout << iter << "," << ga_best << "," << gwo_best << "\n";
    }
    return 0;
}