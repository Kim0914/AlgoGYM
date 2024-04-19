#include <iostream>
#include <vector>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define MAX 99999999

int num = 0, edges = 0, from = 0, to = 0, min_count = MAX;
vector<int> graph[4001];
bool relationship[4001][4001];
void select_friends(int depth, int idx, int sum, int start) {
	if (depth == 3) {
		if (!relationship[start][idx])
			return; // 세 사람 모두 친구여야 함

		int whole_friends = 0;
		min_count = min(sum - 6, min_count);
		return;
	}

	for (int i = idx + 1; i <= num; i++) {
		if (relationship[idx][i])
			select_friends(depth + 1, i, sum + graph[i].size(), start);
	}
}

int main() {
	cin >> num >> edges;
	for (int i = 0; i < edges; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
		
		relationship[from][to] = true;
		relationship[to][from] = true;
	}

	for(int i = 1; i <= num; i++)
		select_friends(1, i, graph[i].size(), i);

	if (min_count == MAX)
		cout << -1;
	else
		cout << min_count;
	return 0;
}

######################################################################################
# 단순 3중포문 버전
	
#include <iostream>
#include <vector>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define MAX 99999999

int num = 0, edges = 0, from = 0, to = 0, min_count = MAX;
vector<int> graph[4001];
bool relationship[4001][4001];
void select_friends(int depth, int idx, int sum, int start) {
	if (depth == 3) {
		if (!relationship[start][idx])
			return; // 세 사람 모두 친구여야 함

		int whole_friends = 0;
		min_count = min(sum - 6, min_count);
		return;
	}

	for (int i = idx + 1; i <= num; i++) {
		if (relationship[idx][i])
			select_friends(depth + 1, i, sum + graph[i].size(), start);
	}
}

int main() {
	cin >> num >> edges;
	for (int i = 0; i < edges; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);

		relationship[from][to] = true;
		relationship[to][from] = true;
	}

	for (int i = 1; i <= num; i++) {
		int whole_friends = 0;
		for (int j = i + 1; j <= num; j++) {
			if (!relationship[i][j])
				continue;

			for (int k = j + 1; k <= num; k++) {
				if (!relationship[i][k] || !relationship[j][k])
					continue;

				whole_friends = graph[i].size();
				whole_friends += graph[j].size();
				whole_friends += graph[k].size();

				min_count = min(whole_friends - 6, min_count);
			}
		}
	}

	if (min_count == MAX)
		cout << -1;
	else
		cout << min_count;

	return 0;
}
