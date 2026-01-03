// Assignment 12:Implementation of Missionaries-Cannibals Problem

#include <bits/stdc++.h>
using namespace std;

struct State {
    int mL, cL, boat; // missionaries left, cannibals left, boat position (0=left,1=right)
    State(int m=0,int c=0,int b=0):mL(m),cL(c),boat(b){}
};

bool is_valid(const State &s) {
    int mR = 3 - s.mL;
    int cR = 3 - s.cL;
    // missionaries not outnumbered on either bank
    if ((s.mL > 0 && s.mL < s.cL) || (mR > 0 && mR < cR)) return false;
    return true;
}

vector<State> get_successors(const State &s) {
    vector<State> succ;
    int dir = s.boat == 0 ? -1 : 1; // if boat on left, move to right: subtract from left
    // possible moves: 1 or 2 missionaries, 1 or 2 cannibals, or one of each
    vector<pair<int,int>> moves = {{1,0},{2,0},{0,1},{0,2},{1,1}};
    for (auto &mv : moves) {
        int m = mv.first * dir;
        int c = mv.second * dir;
        State ns(s.mL + m, s.cL + c, 1 - s.boat);
        if (ns.mL >= 0 && ns.mL <= 3 && ns.cL >= 0 && ns.cL <= 3 && is_valid(ns)) {
            succ.push_back(ns);
        }
    }
    return succ;
}

string to_string(const State &s) {
    ostringstream oss;
    oss << "(M_left=" << s.mL << ", C_left=" << s.cL << ", Boat=" << (s.boat==0?"L":"R") << ")";
    return oss.str();
}

int main() {
    State start(3,3,0);
    State goal(0,0,1);

    queue<State> q;
    unordered_map<int, State> parent;
    unordered_map<int, string> action;
    auto encode = [&](const State &s) {
        return s.mL * 100 + s.cL * 10 + s.boat;
    };
    unordered_set<int> visited;

    q.push(start);
    visited.insert(encode(start));
    parent[encode(start)] = start;

    bool found = false;
    while (!q.empty()) {
        State cur = q.front(); q.pop();
        if (cur.mL == goal.mL && cur.cL == goal.cL && cur.boat == goal.boat) {
            found = true;
            break;
        }
        for (State ns : get_successors(cur)) {
            int code = encode(ns);
            if (visited.count(code)) continue;
            visited.insert(code);
            parent[code] = cur;
            action[code] = to_string(ns) + " from " + to_string(cur);
            q.push(ns);
        }
    }

    if (!found) {
        cout << "No solution found.\n";
        return 0;
    }
    
    // reconstruct path
    vector<State> path;
    State cur = goal;
    while (!(cur.mL==start.mL && cur.cL==start.cL && cur.boat==start.boat)) {
        path.push_back(cur);
        cur = parent[encode(cur)];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    cout << "Solution in " << path.size()-1 << " moves:\n";
    for (auto &st : path) cout << to_string(st) << "\n";
    return 0;
}
