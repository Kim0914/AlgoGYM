#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int tc = 0, num = 0, lines = 0, from = 0, to = 0;
vector<int> graph[1001];
int visit_by_color[1001];
void clear_graph_and_visit() {
	for (int i = 1; i <= num; i++) {
		graph[i].clear();
		visit_by_color[i] = 0;
	}
}

bool bfs(int start) {
	queue<int> bfs_q;
	visit_by_color[start] = 1;
	bfs_q.push(start);

	while (!bfs_q.empty()) {
		int curr_node = bfs_q.front();
		int curr_color = visit_by_color[curr_node];
		bfs_q.pop();

		for (int i = 0; i < graph[curr_node].size(); i++) {
			int next_node = graph[curr_node][i];

			if(visit_by_color[next_node] && curr_color == visit_by_color[next_node])
				// 같은 색이 색칠되었으면, 더 이상 진행할 필요 없음
				return false;

			if (!visit_by_color[next_node]) {
				bfs_q.push(next_node);

				if (curr_color == 1)
					visit_by_color[next_node] = 2;
				if (curr_color == 2)
					visit_by_color[next_node] = 1;
			}
		}
	}

	return true;
}

int main() {
	OPTIMIZE;
	cin >> tc;

	while (tc--) {
		cin >> num >> lines;
		for (int i = 0; i < lines; i++) {
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
			// 양방향 그래프 연결
		}
		
		bool can_color = true;
		for (int i = 1; i <= num; i++) {
			if(!visit_by_color[i])
				can_color = bfs(i);
			
			if (!can_color) {
				cout << "impossible\n";
				break;
			}
		}

		if(can_color)
			cout << "possible\n";
		clear_graph_and_visit();
	}

	return 0;
}
