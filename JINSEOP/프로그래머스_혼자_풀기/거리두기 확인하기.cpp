#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1 };
bool visit[5][5];
void clear_visit() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            visit[i][j] = false;
}

bool bfs(int start_x, int start_y, vector<string> places) {
    queue<pair<pair<int, int>, int>> bfs_q;
    bfs_q.push({ { start_x, start_y }, 0 });
    visit[start_x][start_y] = true;
    
    while (!bfs_q.empty()) {
        int curr_x = bfs_q.front().first.first;
        int curr_y = bfs_q.front().first.second;
        int curr_distance = bfs_q.front().second;
        bfs_q.pop();

        if (curr_distance == 2)
            continue;
        // 거리가 2 이상 지났을 때는 더 이상 탐색하지 않는다.

        for (int i = 0; i < 4; i++) {
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];

            if ((nx >= 0 && nx < 5) && (ny >= 0 && ny < 5)) {
                if (!visit[nx][ny]) {
                    if (places[nx][ny] == 'O') {
                        bfs_q.push({ { nx, ny }, curr_distance + 1 });
                        visit[nx][ny] = true;
                        // O가 나왔다면 계속 진행해도 된다.
                        // X(파티션)는 탐색할 수 없는 위치이다.
                    }
                    else if (places[nx][ny] == 'P')
                        return false;
                    // 맨하탄 거리 2 내에서 사람을 만나면 false 반환
                    // 그럼 대각선에 있는 사람은요?
                    // 대각선에 있는 사람은 거리가 1 떨어진 사람이니까, 다음 탐색 때 걸림
                }
            }
        }
    }

    return true;
    // 무사히 지켜지면 true를 반환
}

int search_room(vector<string> places) {
    bool is_allowed = true;

    for (int i = 0; i < places.size(); i++) {
        for (int j = 0; j < places.size(); j++) {
            if (places[i][j] == 'P') {
                if (bfs(i, j, places) == 0)
                    return 0;
            }
            // 사람인 위치에서만 시작해서 검사한다.
            // 중간에 false가 반환되었다면, 그대로 끝내도 된다.
        }
    }

    return 1;
    // 중간에 false가 반환되지 않았다면, 거리두기가 잘 된 곳!
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i = 0; i < places.size(); i++) {
        answer.push_back(search_room(places[i]));
        clear_visit();
      // 다음 대기실을 탐색할 때 반드시 visit을 비워주어야 한다.
    }

    return answer;
}

int main() {
    vector<vector<string>> places = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                                      {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                                      {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                                      {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                                      {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
    // 5개의 대기실, 각 대기실은 5x5로 동일.
    // 맨해튼 거리가 2 이하로 앉아지도록. (파티션은 예외)
    solution(places);
    return 0;
}
