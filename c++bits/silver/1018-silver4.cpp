#include <iostream>
#include <vector>
using namespace std;

int black(vector<vector<char>> board, int x, int y) {
    int change = 0;
    int i, k;
    
    for (i = x; i < x + 8; i = i + 2) {
        for (k = y; k < y + 8; k = k + 2)
            if (board[i][k] == 'W') change++;
        for (k = y + 1; k < y + 8; k = k + 2)
            if (board[i][k] == 'B') change++;
    }
    for (i = x + 1; i < x + 8; i = i + 2) {
        for (k = y; k < y + 8; k = k + 2)
            if (board[i][k] == 'B') change++;
        for (k = y + 1; k < y + 8; k = k + 2)
            if (board[i][k] == 'W') change++;
    }

    return change;
}

int white(vector<vector<char>> board, int x, int y) {
    int change = 0;
    int i, k;

    for (i = x; i < x + 8; i = i + 2) {
        for (k = y; k < y + 8; k = k + 2)
            if (board[i][k] == 'B') change++;
        for (k = y + 1; k < y + 8; k = k + 2)
            if (board[i][k] == 'W') change++;
    }

    for (i = x + 1; i < x + 8; i = i + 2) {
        for (k = y; k < y + 8; k = k + 2)
            if (board[i][k] == 'W') change++;
        for (k = y + 1; k < y + 8; k = k + 2)
            if (board[i][k] == 'B') change++;
    }

    return change;
}


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> board(N, vector<char>(M));

    // 보드 입력
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    int minChange = 64; // 최대 변경 횟수는 64 ,8x8 전체 변경

    // 왼쪽 위 칸이 흰색인 경우를 고려
    for (int i = 0; i <= N - 8; i++)
        for (int j = 0; j <= M - 8; j++) {
            int changeCount = white(board, i, j);
            minChange = min(minChange, changeCount);
        }

    // 왼쪽 위 칸이 검은색인 경우를 고려
    for (int i = 0; i <= N - 8; i++)
        for (int j = 0; j <= M - 8; j++) {
            int changeCount = black(board, i, j);
            minChange = min(minChange, changeCount);
        }

    cout << minChange << endl;

    return 0;
}
