#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const char EMPTY = ' ';
const char PLAYER_X = 'X'; // Jogador
const char PLAYER_O = 'O'; // Bot

void printBoard(const vector<char>& board) {
    for (int i = 0; i < 9; ++i) {
        cout << board[i];
        if (i % 3 == 2) {
            cout << endl;
        } else {
            cout << " | ";
        }
    }
}

bool isGameOver(const vector<char>& board) {
    for (int i = 0; i < 3; ++i) {
        if (board[i] != EMPTY && board[i] == board[i + 3] && board[i] == board[i + 6]) {
            return true; // Vitoria vertical
        }
        if (board[3 * i] != EMPTY && board[3 * i] == board[3 * i + 1] && board[3 * i] == board[3 * i + 2]) {
            return true; // Vitoria horizontal
        }
    }
    if (board[0] != EMPTY && board[0] == board[4] && board[0] == board[8]) {
        return true; // Diagonal 1
    }
    if (board[2] != EMPTY && board[2] == board[4] && board[2] == board[6]) {
        return true; // Diagonal 2
    }

    for (char cell : board) {
        if (cell == EMPTY) {
            return false; // Jogo nao terminou
        }
    }
    return true; // empate
}

// Minimax com uma IA mais agressiva
int minimax(vector<char>& board, char player, int depth, int alpha, int beta) {
    if (isGameOver(board) || depth == 0) {
        if (player == PLAYER_X) {
            return -1; // Jogador ganha
        } else if (player == PLAYER_O) {
            return 1; // IA ganha
        } else {
            return 0; // empate
        }
    }

    vector<int> scores;
    for (int i = 0; i < 9; ++i) {
        if (board[i] == EMPTY) {
            board[i] = player;
            if (player == PLAYER_X) {
                alpha = max(alpha, minimax(board, PLAYER_O, depth - 1, alpha, beta));
                scores.push_back(alpha);
            } else {
                beta = min(beta, minimax(board, PLAYER_X, depth - 1, alpha, beta));
                scores.push_back(beta);
            }
            board[i] = EMPTY;

            if (alpha >= beta) {
                break;
            }
        }
    }

    if (player == PLAYER_X) {
        int maxScore = -INT_MAX;
        for (int score : scores) {
            maxScore = max(maxScore, score);
        }
        return maxScore;
    } else {
        int minScore = INT_MAX;
        for (int score : scores) {
            minScore = min(minScore, score);
        }
        return minScore;
    }
}

int findBestMove(vector<char>& board) {
    int bestMove = -1;
    int bestScore = -INT_MAX;
    int alpha = -INT_MAX;
    int beta = INT_MAX;
    int depth = 5;

    for (int i = 0; i < 9; ++i) {
        if (board[i] == EMPTY) {
            board[i] = PLAYER_O;
            int score = minimax(board, PLAYER_X, depth, alpha, beta);
            board[i] = EMPTY;

            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }

    return bestMove;
}

int main() {
    vector<char> board(9, EMPTY);
    int currentPlayer = PLAYER_X;

    printBoard(board);

    while (!isGameOver(board)) {
        if (currentPlayer == PLAYER_X) {
            int move;
            do {
                cout << "Sua vez (0-8): ";
                cin >> move;
            } while (move < 0 || move > 8 || board[move] != EMPTY);
            board[move] = PLAYER_X;
        } else {
            int bestMove = findBestMove(board);
            board[bestMove] = PLAYER_O;
            cout << "Vez da maquina:" << endl;
        }

        printBoard(board);
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    if (isGameOver(board)) {
        if (minimax(board, PLAYER_X, 5, -INT_MAX, INT_MAX) == 1) {
            cout << "Perdeu" << endl;
        } else if (minimax(board, PLAYER_X, 5, -INT_MAX, INT_MAX) == -1) {
            cout << "Ganhou!" << endl;
        } else {
            cout << "Empate" << endl;
        }
    }

    return 0;
}
