#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num = 0, cost = 0, precede_num = 0, precede = 0, answer = 0;
int indegree[10001], costs[10001];
vector<int> graph[10001];
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

void topology_sort() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> bfs_q;

	for (int i = 1; i <= num; i++)
		if(!indegree[i])
			bfs_q.push({ i, costs[i] }); // 시작 작업 1번

	while (!bfs_q.empty()) {
		int curr_task = bfs_q.top().first;
		int curr_time = bfs_q.top().second;
		answer = curr_time;
		bfs_q.pop();

		for (int i = 0; i < graph[curr_task].size(); i++) {
			int next_task = graph[curr_task][i];
			int next_time = curr_time + costs[next_task];
			indegree[next_task]--;
			// 선행 작업을 처리했으므로 진입차수 감소

			if (!indegree[next_task])
				bfs_q.push({ next_task, curr_time + costs[next_task]});
			// 진입차수가 0이 된 작업은 수행이 가능하다.
			// 선행 작업이 모두 끝났다는 말!
		}
	}
}

int main() {
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> cost >> precede_num;

		costs[i] = cost;
		indegree[i] = precede_num;
		for (int j = 0; j < precede_num; j++) {
			cin >> precede;
			graph[precede].push_back(i);
		}
	}

	topology_sort();
	cout << answer;
	return 0; 
}
