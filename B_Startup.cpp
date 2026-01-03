#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

long long getMaxEarnings(int n, int k, vector<pair<int, int>>& bottles) {
    // Map to store costs of each brand
    map<int, vector<int>> brandToCosts;
    
    // Group bottle costs by brand
    for (const auto& bottle : bottles) {
        int brand = bottle.first;
        int cost = bottle.second;
        brandToCosts[brand].push_back(cost);
    }
    
    // Vector to store maximum earnings for each brand
    vector<long long> maxEarnings;
    
    // For each brand, sort costs in descending order and compute the highest possible earnings
    for (auto& entry : brandToCosts) {
        auto& costs = entry.second;
        sort(costs.rbegin(), costs.rend()); // Sort in descending order
        
        // Compute cumulative earnings for this brand and add only the best cumulative sum
        long long currentSum = 0;
        for (int i = 0; i < costs.size(); ++i) {
            currentSum += costs[i];
        }
        maxEarnings.push_back(currentSum);
    }
    
    // Sort all possible earnings from different brands in descending order
    sort(maxEarnings.rbegin(), maxEarnings.rend());
    
    // Sum the highest `n` earnings (or fewer if there aren't enough)
    long long result = 0;
    for (int i = 0; i < min(n, (int)maxEarnings.size()); ++i) {
        result += maxEarnings[i];
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> bottles(k);
        for (int i = 0; i < k; ++i) {
            cin >> bottles[i].first >> bottles[i].second;
        }
        
        cout << getMaxEarnings(n, k, bottles) << endl;
    }
    
    return 0;
}
