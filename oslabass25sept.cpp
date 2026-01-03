#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>  // For sleep

using namespace std;

class DiningPhilosophers {
private:
    int num_philosophers;
    vector<mutex> forks;           // One fork between each two philosophers
    vector<condition_variable> conditions;
    vector<bool> fork_available;

public:
    DiningPhilosophers(int n) : num_philosophers(n), forks(n), fork_available(n, true), conditions(n) {}

    // Pick up forks (with asymmetry for odd/even philosophers)
    void pickUp(int philosopher_id) {
        unique_lock<mutex> lock(forks[philosopher_id]);

        int left = philosopher_id;
        int right = (philosopher_id + 1) % num_philosophers;

        // Odd-numbered philosophers pick left first, even-numbered pick right first
        if (philosopher_id % 2 == 0) {
            // Even philosopher picks right fork first
            conditions[right].wait(lock, [this, right]() { return fork_available[right]; });
            fork_available[right] = false;  // Pick right fork
            cout << "Philosopher " << philosopher_id << " picked up right fork " << right << endl;

            conditions[left].wait(lock, [this, left]() { return fork_available[left]; });
            fork_available[left] = false;  // Pick left fork
            cout << "Philosopher " << philosopher_id << " picked up left fork " << left << endl;
        } else {
            // Odd philosopher picks left fork first
            conditions[left].wait(lock, [this, left]() { return fork_available[left]; });
            fork_available[left] = false;  // Pick left fork
            cout << "Philosopher " << philosopher_id << " picked up left fork " << left << endl;

            conditions[right].wait(lock, [this, right]() { return fork_available[right]; });
            fork_available[right] = false;  // Pick right fork
            cout << "Philosopher " << philosopher_id << " picked up right fork " << right << endl;
        }
    }

    // Put down forks (left and right)
    void putDown(int philosopher_id) {
        unique_lock<mutex> lock(forks[philosopher_id]);

        int left = philosopher_id;
        int right = (philosopher_id + 1) % num_philosophers;

        // Release both forks
        fork_available[left] = true;
        fork_available[right] = true;

        cout << "Philosopher " << philosopher_id << " put down forks " << left << " and " << right << endl;

        conditions[left].notify_one();
        conditions[right].notify_one();
    }

    // Philosopher's thinking and eating
    void philosopher(int philosopher_id) {
        while (true) {
            cout << "Philosopher " << philosopher_id << " is thinking...\n";
            this_thread::sleep_for(chrono::milliseconds(1000));

            pickUp(philosopher_id);

            cout << "Philosopher " << philosopher_id << " is eating...\n";
            this_thread::sleep_for(chrono::milliseconds(2000));

            putDown(philosopher_id);
        }
    }
};

int main() {
    int num_philosophers = 5;
    DiningPhilosophers dp(num_philosophers);

    vector<thread> threads;
    for (int i = 0; i < num_philosophers; ++i) {
        threads.emplace_back(&DiningPhilosophers::philosopher, &dp, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
