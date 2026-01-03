// Assignment 6: Implement local search algorithm Hill Climbing on a problem with multiple local optima. 

#include <bits/stdc++.h>
using namespace std;

double rastrigin(const vector<double>& x) {
    const double A = 10.0;
    double sum = A * x.size();
    for (double xi : x) {
        sum += xi*xi - A * cos(2 * M_PI * xi);
    }
    return sum;
}

vector<double> random_solution(int dim, double lb, double ub, mt19937& gen) {
    uniform_real_distribution<double> dist(lb, ub);
    vector<double> sol(dim);
    for (int i = 0; i < dim; ++i) sol[i] = dist(gen);
    return sol;
}

vector<vector<double>> get_neighbors(const vector<double>& sol, double step, double lb, double ub) {
    int dim = sol.size();
    vector<vector<double>> neighs;
    for (int i = 0; i < dim; ++i) {
        vector<double> plus = sol, minus = sol;
        plus[i] = min(ub, plus[i] + step);
        minus[i] = max(lb, minus[i] - step);
        neighs.push_back(plus);
        neighs.push_back(minus);
    }
    return neighs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dim = 2;
    double lb = -5.12, ub = 5.12;
    double step = 0.1;
    int max_iters = 1000;
    int restarts = 10;

    mt19937 gen(random_device{}());

    double global_best_val = numeric_limits<double>::infinity();
    vector<double> global_best;

    for (int r = 0; r < restarts; ++r) {
        // initialize random solution
        vector<double> current = random_solution(dim, lb, ub, gen);
        double current_val = rastrigin(current);

        for (int iter = 0; iter < max_iters; ++iter) {
            auto neighs = get_neighbors(current, step, lb, ub);
            vector<double> best_neighbor = current;
            double best_val = current_val;
            for (auto& nsol : neighs) {
                double val = rastrigin(nsol);
                if (val < best_val) {
                    best_val = val;
                    best_neighbor = nsol;
                }
            }
            // if no improvement, break
            if (best_val >= current_val) break;
            current = best_neighbor;
            current_val = best_val;
        }

        cout << "Restart " << r << ": best=" << current_val << " at (";
        for (int i = 0; i < dim; ++i) cout << current[i] << (i+1<dim?",":"");
        cout << ")\n";

        if (current_val < global_best_val) {
            global_best_val = current_val;
            global_best = current;
        }
    }

    cout << "Global best: " << global_best_val << " at (";
    for (int i = 0; i < dim; ++i) cout << global_best[i] << (i+1<dim?",":"");
    cout << ")\n";
    return 0;
}
