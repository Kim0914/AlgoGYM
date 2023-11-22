#include <iostream>
#include <string>
using namespace std;

int row = 0, col = 0, answer = 0, paper[500][500];
bool visit[500][500];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void additional_shape(int x, int y) {
    if ((x - 1 >= 0) && (y + 2 < col)) {
        // ㅗ 모양
        int sum = 0;
        sum = paper[x][y] + paper[x][y + 1] + paper[x][y + 2] + paper[x - 1][y + 1];
        answer = max(answer, sum);
    }
    if ((x + 1 < row) && (y + 2) < col) {
        // ㅜ 모양
        int sum = 0;
        sum = paper[x][y] + paper[x][y + 1] + paper[x][y + 2] + paper[x + 1][y + 1];
        answer = max(answer, sum);
    }
    if ((x + 2 < row) && (y + 1) < col) {
        // ㅏ 모양
        int sum = 0;
        sum = paper[x][y] + paper[x + 1][y] + paper[x + 2][y] + paper[x + 1][y + 1];
        answer = max(answer, sum);
    }
    if ((x + 1 < row) && (x - 1 >= 0) && (y + 1 < col)) {
        // ㅓ 모양
        int sum = 0;
        sum = paper[x][y] + paper[x - 1][y + 1] + paper[x][y + 1] + paper[x + 1][y + 1];
        answer = max(answer, sum);
    }
}

void backtrack(int depth, int sum, int start_x, int start_y) {
    if (depth == 4) {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = start_x + dx[i];
        int ny = start_y + dy[i];
        if ((nx >= 0 && nx < row) && (ny >= 0 && ny < col)) {
            if (!visit[nx][ny]) {
                visit[nx][ny] = true;
                backtrack(depth + 1, sum + paper[nx][ny], nx, ny);
                visit[nx][ny] = false;
            }
        }
    }
}

int main(){
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> paper[i][j];
        }
    }

    // 내가 생각한 풀이는, DFS를 4칸씩 백트래킹 돌리면?
    // 테트로미노 모양을 모두 만들 수 있다.

    // 어? ㅗ ㅜ ㅏ ㅓ 모양은 DFS만으로는 만들 수 없음이 문제가 됐다.
    // 생각해보면 해당 모양의 탐색 순서는 BFS일 때 가능한 순서이다.
    // 그럼 BFS를 한번 더 돌린다..?
    // 그냥 모양을 직접 만들어서 추가로 탐색해주자.

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            visit[i][j] = true;
            backtrack(0, 0, i, j);
            visit[i][j] = false;
            // 시간초과가 과연 안날까?
            // 중복되는 모양을 제거해서 pruning 가능성은?
            additional_shape(i, j);
        }
    }

    cout << answer;
    return 0;
}
