#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> mount_road[50001];
int min_intensity = 999999999, final_summit = 0;
bool visit[50001];
void make_map(vector<vector<int>> paths) {
	for (int i = 0; i < paths.size(); i++) {
		int from = paths[i][0];
		int to = paths[i][1];
		int cost = paths[i][2];

		mount_road[from].push_back({cost, to});
		mount_road[to].push_back({ cost, from });
	}
}

void clear_visit(int n){
	for (int i = 0; i <= n; i++)
		visit[i] = false;
}

bool check_summit(int curr_point, vector<int> summits) {
	for (int i = 0; i < summits.size(); i++)
		if (curr_point == summits[i])
			return true;

	return false;
}

void check_enterance(int curr_point, vector<int> gates) {
	for (int i = 0; i < gates.size(); i++) {
		if (gates[i] == curr_point)
			continue;
		
		visit[gates[i]] = true;
	}
}

void backtrack(int start_point, int curr_point, int curr_cost, vector<int> summits, vector<int> gates) {
	if (check_summit(curr_point, summits)) {
		if (curr_cost != 0) {
			min_intensity = min(min_intensity, curr_cost);
			final_summit = curr_point;
		}

		return;
	}

	for (int i = 0; i < mount_road[curr_point].size(); i++) {
		int next_point = mount_road[curr_point][i].second; // 다음 경로
		int next_cost = mount_road[curr_point][i].first; // 드는 비용

		if (!visit[next_point]) {
			visit[next_point] = true;

			backtrack(start_point, next_point, max(next_cost, curr_cost), summits, gates);
			visit[next_point] = false;
		}
	}
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	vector<int> answer;

	make_map(paths);
	for (int i = 0; i < gates.size(); i++) {
		visit[gates[i]] = true; // 시작 지점 방문
		check_enterance(gates[i], gates);

		backtrack(gates[i], gates[i], 0, summits, gates);
		clear_visit(n);
	}

	answer.push_back(final_summit);
	answer.push_back(min_intensity);
	
	cout << answer[0] << " " << answer[1] << '\n';
	return answer;
}

int main() {
	solution(6, { {1,2,3}, {2,3,5}, {2,4,2}, {2,5,4}, {3,4,4}, {4,5,3}, {4,6,1}, {5,6,1} },
				{ 1, 3 }, { 5 });
	return 0;
}
