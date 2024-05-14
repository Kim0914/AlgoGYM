#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int tc = 0;
int button_arr[5], button_info[4];
bool visit[80];
void init_button() {
	button_info[0] = 10;
	button_info[1] = -10;
	button_info[2] = 1;
	button_info[3] = -1;
}

void clear_visit() {
	for (int i = 0; i <= 60; i++)
		visit[i] = false;
}

vector<int> bfs(int target) {
	clear_visit();

	queue<vector<int>> bfs_q;
	bfs_q.push({0, 0, 0, 0, 0}); // 시작은 반드시 0
	visit[0] = true;

	while (!bfs_q.empty()) {
		vector<int> curr_state = bfs_q.front();
		bfs_q.pop();

		if (curr_state[4] == target) {
			curr_state.pop_back();
			return curr_state;
		}

		for (int i = 0; i < 4; i++) {
			int next_time = curr_state[4] + button_info[i];

			if (next_time < 0 || next_time > 70)
				continue;
			
			if (!visit[next_time]) {
				vector<int> next_vec = curr_state;
				next_vec[i]++;
				next_vec[4] = next_time;

				bfs_q.push(next_vec);
				visit[next_time] = true;
			}
		}
	}
}

int main() {
	// 시작 시간은 0분, 0분 미만은 없음
	cin >> tc;

	int target = 0;
	// 순서대로 ADDH, ADDT, MINT, ADDO, MINO
	init_button();

	while (tc--) {
		cin >> target;

		int h_cnt = target / 60; // 60+를 누른 횟수
		int rest_time = target % 60; // 60보다 크면 누르는게 이득임

		int o_cnt = h_cnt;
		vector<int> answer_o;
		answer_o.push_back(h_cnt);
		for (int i : bfs(rest_time)) {
			answer_o.push_back(i);
			o_cnt += i;
		}

		int t_cnt = h_cnt + 1;
		vector<int> answer_t;
		answer_t.push_back(h_cnt + 1);
		for (int i : bfs(60 - rest_time)) {
			answer_t.push_back(i);
			t_cnt += i;
		}
		swap(answer_t[1], answer_t[2]);
		swap(answer_t[3], answer_t[4]);

		if (o_cnt > t_cnt)
			for (int i : answer_t)
				cout << i << " ";
		else
			for (int i : answer_o)
				cout << i << " ";
		cout << '\n';
	}

	return 0;
}
