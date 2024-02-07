#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>

bool visit[1001][1001];
int bfs(piii start_state, int sum) {
    queue<pii> bfs_q;
    bfs_q.push({start_state.first, start_state.second.first});
    visit[start_state.first][start_state.second.first] = true;

    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().first;
        int curr_y = bfs_q.front().second;
        int curr_z = sum - curr_x - curr_y;
        // 나머지 하나의 수는 그냥 차연산으로 도출
        bfs_q.pop();

        if (curr_x == curr_y && curr_y == curr_z)
            return 1;

        int dx[3] = { curr_x, curr_x, curr_y };
        int dy[3] = { curr_y, curr_z, curr_z };
        // 두 수를 고르는 경우는 세 가지.
        for (int i = 0; i < 3; i++) {
            int nx = dx[i];
            int ny = dy[i];

            if (nx < ny) {
                ny -= nx;
                nx += nx;
            }
            else if (nx > ny) {
                nx -= ny;
                ny += ny;
            }
            else
                continue;
            // 선택한 두 수가 같으면 고를 수 없다.
            int nz = sum - nx - ny;
            // 두 수가 결정되면 나머지 하나의 수는 자동 결정

            int min_n = min(min(nx, ny), nz);
            int max_n = max(max(nx, ny), nz);
            // 이 부분은 순서가 다르지만 같은 조합을 거르기 위함이다.  
            // 예를들어, 20 15 25와 15 20 25는 순서가 다르지만 같은 조합이다.
            // 따라서 동일한 최대, 최소를 방문했음을 표시해서 중복을 방지한다.
            
            if (!visit[min_n][max_n]) {
                visit[min_n][max_n] = true;
                bfs_q.push({ nx, ny });
            }
        }
    }

    return 0;
}

int main() {
    piii stones;
    cin >> stones.first;
    cin >> stones.second.first;
    cin >> stones.second.second;

    int sum = stones.first + stones.second.first + stones.second.second;
    if ((sum % 3) != 0)
        cout << 0;
    // 세 수를 공평하게 분배할 수 없으면 무조건 안된다.
    else
        cout << bfs(stones, sum);

    return 0;
}
