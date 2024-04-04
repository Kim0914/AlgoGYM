#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int num = 0, pre_num = 0, from = 0, to = 0;
vector<int> graph[1001];
int indegree[1001];
int result[1001];
void init_result() {
	for (int i = 1; i <= num; i++)
		result[i] = 1;
	// 모든 과목을 1로 초기화 해야함
}

void topology_sort() {
	queue<int> top_q;

	for (int i = 1; i <= num; i++)
		if (!indegree[i])
			top_q.push(i);
	// 진입 차수가 0인 과목부터

	while (!top_q.empty()) {
		int prerequisite = top_q.front();
		top_q.pop();

		for (int i = 0; i < graph[prerequisite].size(); i++) {
			int next_sub = graph[prerequisite][i];
			indegree[next_sub]--;
			result[next_sub] = max(result[next_sub], result[prerequisite] + 1); 
			// 선수과목에 대해 한 학기 더 들어야 함.

			if (!indegree[next_sub])
				top_q.push(next_sub);
		}
	}
}

int main(){
	cin >> num >> pre_num;
	for (int i = 0; i < pre_num; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		indegree[to]++;
	}

	init_result();
	topology_sort(); // 위상정렬 진행
	// result 배열을 어떻게 채울 것인가?
	
	for (int i = 1; i <= num; i++)
		cout << result[i] << " ";
	return 0;
}
