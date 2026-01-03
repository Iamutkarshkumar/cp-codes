#include <bits/stdc++.h>
using namespace std;

const char NONE = '_', HUMAN = 'X', AI = 'O';

// Check if moves are left on board
bool isMovesLeft(const vector<vector<char>>& board) {
    for (auto& row : board)
        for (char c : row)
            if (c == NONE) return true;
    return false;
}

// Evaluate board: +10 for AI win, -10 for Human win, 0 otherwise
int evaluate(const vector<vector<char>>& b) {
    // Rows
    for (int row = 0; row < 3; row++) {
        if (b[row][0] == b[row][1] && b[row][1] == b[row][2] && b[row][0] != NONE) {
            if (b[row][0] == AI) return +10;
            else if (b[row][0] == HUMAN) return -10;
        }
    }
    // Columns
    for (int col = 0; col < 3; col++) {
        if (b[0][col] == b[1][col] && b[1][col] == b[2][col] && b[0][col] != NONE) {
            if (b[0][col] == AI) return +10;
            else if (b[0][col] == HUMAN) return -10;
        }
    }
    // Diagonals
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0] != NONE) {
        if (b[0][0] == AI) return +10;
        else if (b[0][0] == HUMAN) return -10;
    }
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[0][2] != NONE) {
        if (b[0][2] == AI) return +10;
        else if (b[0][2] == HUMAN) return -10;
    }
    return 0;
}

// Minimax without pruning
int minimax(vector<vector<char>>& board, int depth, bool isMax) {
    int score = evaluate(board);
    if (score == 10 || score == -10) return score;
    if (!isMovesLeft(board)) return 0;
    
    if (isMax) {
        int best = INT_MIN;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == NONE) {
                    board[i][j] = AI;
                    best = max(best, minimax(board, depth + 1, !isMax));
                    board[i][j] = NONE;
                }
            }
        }
        return best;
    } else {
        int best = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == NONE) {
                    board[i][j] = HUMAN;
                    best = min(best, minimax(board, depth + 1, !isMax));
                    board[i][j] = NONE;
                }
            }
        }
        return best;
    }
}

// Minimax with Alpha-Beta pruning
int alphabeta(vector<vector<char>>& board, int depth, int alpha, int beta, bool isMax) {
    int score = evaluate(board);
    if (score == 10 || score == -10) return score;
    if (!isMovesLeft(board)) return 0;
    
    if (isMax) {
        int best = INT_MIN;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == NONE) {
                    board[i][j] = AI;
                    int val = alphabeta(board, depth + 1, alpha, beta, !isMax);
                    best = max(best, val);
                    alpha = max(alpha, best);
                    board[i][j] = NONE;
                    if (beta <= alpha) return best;  // beta cut-off
                }
            }
        }
        return best;
    } else {
        int best = INT_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == NONE) {
                    board[i][j] = HUMAN;
                    int val = alphabeta(board, depth + 1, alpha, beta, !isMax);
                    best = min(best, val);
                    beta = min(beta, best);
                    board[i][j] = NONE;
                    if (beta <= alpha) return best; // alpha cut-off
                }
            }
        }
        return best;
    }
}

// Find best move for AI
pair<int,int> findBestMove(vector<vector<char>>& board, bool useAlphaBeta) {
    int bestVal = INT_MIN;
    pair<int,int> bestMove = {-1,-1};
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == NONE) {
                board[i][j] = AI;
                int moveVal = useAlphaBeta ? 
                    alphabeta(board, 0, INT_MIN, INT_MAX, false) :
                    minimax(board, 0, false);
                board[i][j] = NONE;
                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

void printBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (auto& row : board) {
        for (char c : row) cout << c << " ";
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, NONE));
    int choice;
    do {
        cout << "Choose AI algorithm: 1) Minimax  2) Alpha-Beta Pruning\n";
        cin >> choice;
        if (cin.fail() || (choice != 1 && choice != 2)) {
            cout << "Invalid choice. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 1 && choice != 2);
    bool useAlphaBeta = (choice == 2);

    cout << "Human is X, AI is O.\n";
    printBoard(board);

    int row, col;
    for (int turn = 0; isMovesLeft(board) && evaluate(board) == 0; turn++) {
        if (turn % 2 == 0) {
            // Human move
            bool valid = false;
            do {
                cout << "Enter your move (row col): ";
                cin >> row >> col;
                if (cin.fail()) {
                    cout << "Invalid input. Please enter two integers.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if (row < 0 || row > 2 || col < 0 || col > 2) {
                    cout << "Row and column must be between 0 and 2.\n";
                } else if (board[row][col] != NONE) {
                    cout << "Cell already occupied. Try again.\n";
                } else {
                    valid = true;
                }
            } while (!valid);
            board[row][col] = HUMAN;
        } else {
            // AI move
            pair<int, int> move = findBestMove(board, useAlphaBeta);
            if (move.first == -1 || move.second == -1) {
                cout << "No valid moves for AI.\n";
                break;
            }
            board[move.first][move.second] = AI;
            cout << "AI places at " << move.first << "," << move.second << "\n";
        }
        printBoard(board);
    }
    int score = evaluate(board);
    if (score == 10) cout << "AI wins!\n";
    else if (score == -10) cout << "Human wins!\n";
    else cout << "It's a tie!\n";
    return 0;
}