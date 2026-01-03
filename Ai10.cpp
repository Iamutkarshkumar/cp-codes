// Assignment 10:Simulate a basic Wumpus World environment and implement a simple agent that navigates
// through it using propositional logic to avoid dangers (e.g., pits, Wumpus). Track the agent's
// decisions and learning process.

#include <bits/stdc++.h>
using namespace std;

enum Cell { EMPTY, PIT, WUMPUS, GOLD };

typedef pair<int,int> Pos;

struct Environment {
    int N;
    vector<vector<Cell>> grid;
    Pos wumpusPos;
    set<Pos> pitPositions;
    Pos goldPos;
    Environment(int n): N(n), grid(n, vector<Cell>(n, EMPTY)) {}
    void addPit(int r, int c) { grid[r][c] = PIT; pitPositions.insert({r,c}); }
    void addWumpus(int r, int c) { grid[r][c] = WUMPUS; wumpusPos={r,c}; }
    void addGold(int r, int c) { grid[r][c] = GOLD; goldPos={r,c}; }
    
    // Percepts at position (r,c)
    bool breeze(int r, int c) {
        for (auto &d: vector<Pos>{{1,0},{-1,0},{0,1},{0,-1}}) {
            int nr=r+d.first, nc=c+d.second;
            if (nr>=0&&nr<N&&nc>=0&&nc<N && grid[nr][nc]==PIT) return true;
        }
        return false;
    }
    bool stench(int r,int c) {
        for (auto &d: vector<Pos>{{1,0},{-1,0},{0,1},{0,-1}}) {
            int nr=r+d.first, nc=c+d.second;
            if (nr>=0&&nr<N&&nc>=0&&nc<N && grid[nr][nc]==WUMPUS) return true;
        }
        return false;
    }
    bool glitter(int r,int c) { return grid[r][c]==GOLD; }
};

struct Agent {
    int N;
    Pos pos;
    set<Pos> visited;
    vector<vector<bool>> safe, visitedArr;
    vector<vector<int>> probPit, probWumpus;
    vector<string> log;
    Agent(int n): N(n), pos({0,0}),
        safe(n, vector<bool>(n,false)), visitedArr(n, vector<bool>(n,false)),
        probPit(n, vector<int>(n,0)), probWumpus(n, vector<int>(n,0)) {
        safe[0][0] = true; visitedArr[0][0]=true; visited.insert(pos);
        log.push_back("Start at (0,0)");
    }
    
    vector<Pos> neighbors(Pos p) {
        vector<Pos> res;
        for (auto &d: vector<Pos>{{1,0},{-1,0},{0,1},{0,-1}}) {
            int nr=p.first+d.first, nc=p.second+d.second;
            if (nr>=0&&nr<N&&nc>=0&&nc<N) res.push_back({nr,nc});
        }
        return res;
    }
    
    // Update knowledge base based on percepts
    void perceive(Environment &env) {
        int r=pos.first, c=pos.second;
        bool b = env.breeze(r,c);
        bool s = env.stench(r,c);
        bool g = env.glitter(r,c);
        log.push_back("Percepts at ("+to_string(r)+","+to_string(c)+"): breeze="+to_string(b)+", stench="+to_string(s)+", glitter="+to_string(g));
        for (auto &nbr : neighbors(pos)) {
            if (!safe[nbr.first][nbr.second]) {
                if (!b) { safe[nbr.first][nbr.second]=true; log.push_back("Mark safe " + to_string(nbr.first) + "," + to_string(nbr.second)); }
                else probPit[nbr.first][nbr.second]++;
                if (!s) { safe[nbr.first][nbr.second]=true; log.push_back("Mark safe " + to_string(nbr.first) + "," + to_string(nbr.second)); }
                else probWumpus[nbr.first][nbr.second]++;
            }
        }
        if (g) { log.push_back("Found gold!"); }
    }
    
    // Choose next move: any unvisited safe neighbor, else None
    bool move() {
        for (auto &nbr : neighbors(pos)) {
            if (safe[nbr.first][nbr.second] && !visitedArr[nbr.first][nbr.second]) {
                pos = nbr;
                visitedArr[pos.first][pos.second]=true;
                visited.insert(pos);
                log.push_back("Move to ("+to_string(pos.first)+","+to_string(pos.second)+")");
                return true;
            }
        }
        return false;
    }
};

int main(){
    int N=4;
    Environment env(N);
    // Setup world
    env.addPit(1,3);
    env.addPit(3,0);
    env.addWumpus(2,2);
    env.addGold(0,3);
    
    Agent agent(N);
    bool foundGold=false;
    
    for (int step=0; step<100; ++step) {
        agent.perceive(env);
        if (env.glitter(agent.pos.first, agent.pos.second)) { foundGold=true; break; }
        if (!agent.move()) break;
    }
    
    cout<<"=== Agent Log ===\n";
    for (auto &line: agent.log) cout<<line<<"\n";
    cout<<(foundGold?"Gold retrieved!":"Failed to find gold.")<<"\n";
    return 0;
}