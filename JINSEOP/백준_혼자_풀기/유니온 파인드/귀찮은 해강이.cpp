#include <iostream>
#include <vector>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int num = 0, edges = 0, from = 0, to = 0;
vector<int> graph[100001];
int lectures[100001];
int main() {
	OPTIMIZE;

	cin >> num >> edges;
	for (int i = 0; i < edges; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= num; i++)
		cin >> lectures[i];

	bool is_connected = false;
	int answer = 0;
	for (int i = 2; i <= num; i++) {
		int curr_lecture = lectures[i];

		for (int j = 0; j < graph[curr_lecture].size(); j++) {
			if (graph[curr_lecture][j] == lectures[i - 1]) {
				is_connected = true;
				break;
			}
		}

		if (!is_connected)
			answer++;
	}

	cout << answer;
	return 0;
}
