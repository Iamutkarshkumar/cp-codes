vector<string> getAllPermutations(string str) {
    vector<string> permutations;
    sort(str.begin(), str.end());  
    do {
        permutations.push_back(str);
    } while (next_permutation(str.begin(), str.end()));

    return permutations;
}
