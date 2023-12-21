#include <iostream>
#include <queue>
using namespace std;

int story = 0, comp_floor = 0, curr_floor = 0, up_butt = 0, dn_butt = 0;
bool visit[1000001];
void bfs() {
    queue<pair<int, int>> bfs_q;
    bfs_q.push({ curr_floor, 0 });
    visit[curr_floor] = true;
    // 강호의 현재 위치 입력

    while (!bfs_q.empty()) {
        int curr = bfs_q.front().first;
        int curr_cnt = bfs_q.front().second;
        bfs_q.pop();

        if (curr == comp_floor) {
            cout << curr_cnt;
            return;
        }

        int upper_floor = curr + up_butt;
        int lower_floor = curr - dn_butt;
        
        if (upper_floor <= story) {
            if (!visit[upper_floor]) {
                bfs_q.push({ upper_floor, curr_cnt + 1 });
                visit[upper_floor] = true;
            }
        }

        if (lower_floor >= 1) {
            if (!visit[lower_floor]) {
                bfs_q.push({ lower_floor, curr_cnt + 1 });
                visit[lower_floor] = true;
            }
        }
    }
    
    cout << "use the stairs";
}

int main() {
    cin >> story >> curr_floor >> comp_floor >> up_butt >> dn_butt;
    bfs();

    return 0;
}
