#include "iostream"
#include "vector"
#include "queue"
#include "unordered_set"
#include "map"
#include <clocale>

using namespace std;

const int N = 3;
const int TOTAL_NUMBERS = N * N;

struct State {
    vector<vector<int>> board;
    int emptyRow, emptyCol;
    string move;

    State(vector<vector<int>> brd, int er, int ec, string mv) : board(brd), emptyRow(er), emptyCol(ec), move(mv) {}
};

bool isValid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

bool isGoalState(const vector<vector<int>>& board) {
    int num = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == N - 1 && j == N - 1) {
                if (board[i][j] != 0) {
                    return false;
                }
            } else if (board[i][j] != num) {
                return false;
            }
            ++num;
        }
    }
    return true;
}

vector<State> getNeighbours(const State& state) {
    vector<State> neighbours;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    string moves[] = {"U", "D", "L", "R"};

    for (int i = 0; i < 4; ++i) {
        int newEmptyRow = state.emptyRow + dr[i];
        int newEmptyCol = state.emptyCol + dc[i];

        if (isValid(newEmptyRow, newEmptyCol)) {
            vector<vector<int>> newBoard = state.board;
            swap(newBoard[state.emptyRow][state.emptyCol], newBoard[newEmptyRow][newEmptyCol]);
            neighbours.emplace_back(newBoard, newEmptyRow, newEmptyCol, state.move + moves[i]);
        }
    }

    return neighbours;
}

bool isSolvable(const vector<vector<int>>& board) {
    int inversions = 0;
    vector<int> flattenedBoard;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] != 0) {
                flattenedBoard.push_back(board[i][j]);
            }
        }
    }

    for (int i = 0; i < TOTAL_NUMBERS - 1; ++i) {
        for (int j = i + 1; j < TOTAL_NUMBERS - 1; ++j) {
            if (flattenedBoard[j] && flattenedBoard[i] && flattenedBoard[i] > flattenedBoard[j]) {
                ++inversions;
            }
        }
    }

    if (inversions % 2 != 0) {
        return false;
    }

    return true;
}

void printMoves(const string& moves) {
    map<char, string> moveNames = {{'U', "Up"}, {'D', "Down"}, {'L', "Left"}, {'R', "Right"}};

    for (char move : moves) {
        cout << moveNames[move] << " ";
    }
    cout << endl;
}

void solvePuzzle(const vector<vector<int>>& initialBoard) {
    if (!isSolvable(initialBoard)) {
        cout << "O tabuleiro informado não é solucionável." << endl;
        return;
    }

    queue<State> q;
    unordered_set<string> visited;

    q.push(State(initialBoard, 0, 0, ""));
    visited.insert(string(initialBoard[0].begin(), initialBoard[N - 1].end()));

    while (!q.empty()) {
        State currState = q.front();
        q.pop();

        if (isGoalState(currState.board)) {
            cout << "Tabuleiro solucionável! Movimentos para resolver:" << endl;
            printMoves(currState.move);
            return;
        }

        vector<State> neighbours = getNeighbours(currState);

        for (const State& neighbour : neighbours) {
            string neighborStr(neighbour.board[0].begin(), neighbour.board[N - 1].end());

            if (visited.find(neighborStr) == visited.end()) {
                visited.insert(neighborStr);
                q.push(neighbour);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    vector<vector<int>> initialBoard(N, vector<int>(N));

    cout << "Informe a disposição inicial do tabuleiro (use 0 para representar o espaço vazio):" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> initialBoard[i][j];
        }
    }

    solvePuzzle(initialBoard);

    return 0;
}