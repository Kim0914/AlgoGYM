#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int vertex = 0, edge = 0, src = 0, dest = 0, num = 0;
int degree[101], cost[101];
vector<pair<int, int>> graph[101];
vector<int> answer;
void topology_sort() {
	queue<int> top_q;
	top_q.push(vertex);
	cost[vertex] = 1;
	// 진입차수가 0인 노드부터 시작 (완제품)

	while (!top_q.empty()) { // 간선을 제거하며 진행
		int curr = top_q.front();
		top_q.pop();

		if (graph[curr].empty()) // 여기는 기본 부품이라는 말이다.
			answer.push_back(curr);
		// 기본 부품이라 함은 자신을 구성하는 부품이 없어야 한다.
		// 즉, graph에서 비어있다면 기본 부품이 된다.

		for (int i = 0; i < graph[curr].size(); i++) {
			int next_node = graph[curr][i].first;
			int next_cost = graph[curr][i].second;

			degree[next_node]--; // 간선 제거 (진입 차수 내림)
			cost[next_node] += cost[curr] * next_cost; // 비용 추가

			if (degree[next_node] == 0) // 진입차수가 0이 되었으면
				top_q.push(next_node); // 다음 순서로 추가
		}
	}
}

int main() {
	cin >> vertex >> edge;

	for (int i = 0; i < edge; i++) {
		cin >> dest >> src >> num;
		graph[dest].push_back({ src, num });
		degree[src]++;
	}
	
	topology_sort();
	sort(answer.begin(), answer.end());

	for (auto i : answer)
		cout << i << " " << cost[i] << '\n';

	return 0;
}
