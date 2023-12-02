#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int tc = 0, tc_num = 0, vertex = 0, edges = 0, from = 0, to = 0, answer = 0;
int strahler[1001], indegree[1001];
vector<int> graph[1001];
void optimize() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void calculate_strahler() {
    queue<int> topology_q;
    vector<int> cache[1001];
    for (int i = 1; i <= vertex; i++) {
        if (indegree[i] == 0) {
            topology_q.push(i);
            strahler[i] = 1;
            // 진입차수가 0이면 강의 근원이라는 말이다.
        }
    }

    while (!topology_q.empty()) {
        int curr_node = topology_q.front();
        topology_q.pop();

        for (int i = 0; i < graph[curr_node].size(); i++) {
            int next_node = graph[curr_node][i];
            indegree[next_node]--;
            // 탐색을 한 번 했으니 진입 차수 감소
            cache[next_node].push_back(strahler[curr_node]);

            if (indegree[next_node] == 0) {
                topology_q.push(next_node);
                // 진입 차수가 0인 노드가 생기면 큐에 삽입
                int max_strahler = 0;
                for (int i = 0; i < cache[next_node].size(); i++)
                    max_strahler = max(max_strahler, cache[next_node][i]);
                // 노드에 연결되어있던 이전 노드의 strahler 중 최대 값

                int check_strahler = 0;
                for (int i = 0; i < cache[next_node].size(); i++)
                    if (cache[next_node][i] == max_strahler)
                        check_strahler++;

                if (check_strahler > 1)
                    strahler[next_node] = max_strahler + 1;
                else
                    strahler[next_node] = max_strahler;
            }
        }
    }
}

int main() {
    optimize();
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> tc_num >> vertex >> edges;
        for (int j = 0; j < edges; j++) {
            cin >> from >> to;
            graph[from].push_back(to);
            indegree[to]++;
        } // 단방향 그래프 생성 및 진입차수 계산

        calculate_strahler();

        cout << tc_num << " ";

        answer = 0;
        for (int j = 1; j <= vertex; j++)
            answer = max(answer, strahler[j]);
        cout << answer << '\n';

        memset(indegree, 0, sizeof(indegree));
        memset(strahler, 0, sizeof(strahler));
        memset(graph, 0, sizeof(graph));
    }
    return 0;
}
