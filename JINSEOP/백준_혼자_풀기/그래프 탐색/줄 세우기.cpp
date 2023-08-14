#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int vertex = 0, edge = 0, src = 0, dest = 0;
int degree[32001];
vector<vector<int>> graph(32001);
void topology_sort() {
	queue<int> top_q;

	for (int i = 1; i <= vertex; i++)
		if (degree[i] == 0)
			top_q.push(i); // 진입차수가 0인 노드부터 시작

	while (!top_q.empty()) {
		int from = top_q.front();
		top_q.pop();
		cout << from << " ";

		for (int i = 0; i < graph[from].size(); i++) {
			int to = graph[from][i];
			degree[to]--; // from과 연결된 간선 제거
			if (degree[to] == 0)
				top_q.push(to);
		}
	}
}

int main() {
	cin >> vertex >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> src >> dest;
		// 여기서 중요한 점, 어떤 자료구조를 이용할 것인가?
		// 방향이 있는 그래프이므로, 인접 행렬에 한 방향만 저장
		graph[src].push_back(dest);
		degree[dest]++; // 해당 노드의 진입 차수가 몇 인지 저장
	}

	topology_sort();
	return 0;
}
