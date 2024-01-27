#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int>

int indegree[100001];
vector<int> graph[100001];
bool visit[100001];
int topology_sort(int vertex) {
	int answer = 0;

	queue<int> top_q;
	for (int i = 1; i <= vertex; i++)
		if (indegree[i] == 1)
			top_q.push(i);
	// 진입 차수가 1이면 Leaf node.
	
	while (!top_q.empty()) {
		int curr_node = top_q.front();
		top_q.pop();

		for (int i = 0; i < graph[curr_node].size(); i++) {
			int next_node = graph[curr_node][i];
			indegree[next_node]--;

			if (indegree[next_node] == 1)
				top_q.push(next_node);
			if (visit[curr_node] == false)
				visit[next_node] = true;
			// 자식 노드가 꺼져있을 때, 부모노드를 켜는게 핵심이다.
		}
	}

	for (int i = 1; i <= vertex; i++)
		if (visit[i])
			answer++;

	cout << answer;
	return answer;
}

int solution(int n, vector<vector<int>> lighthouse) {
	for (int i = 0; i < lighthouse.size(); i++) {
		int from = lighthouse[i][0];
		int to = lighthouse[i][1];

		graph[from].push_back(to);
		graph[to].push_back(from);
		indegree[from]++;
		indegree[to]++; // 진입 차수
	}

	return topology_sort(n);
}

int main() {
	solution(9, { {1, 2}, {2, 3}, {3, 4},{4, 5},{5, 6},{6, 7},{7, 8},{8, 9} });
	return 0;
}
