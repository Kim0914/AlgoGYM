#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define pii pair<int, int>

int min_waiting_time = 987654321;
int calculate_waiting_time(vector<int> counselors, vector<vector<int>> &reqs) {
	int waiting_time = 0;
	vector<priority_queue<int, vector<int>, greater<int>>> counsel_q(counselors.size());
	// 상담 종료 시간, 상담원 유형

	for (int i = 0; i < reqs.size(); i++) {
		int curr_category = reqs[i][2];

		while (!counsel_q[curr_category - 1].empty() && counsel_q[curr_category - 1].top() <= reqs[i][0]) {
			counsel_q[curr_category - 1].pop();
			counselors[curr_category - 1]++;
		}

		if (counselors[curr_category - 1] == 0) {
		// 진행 가능한 상담원이 없으면?
			int diff = counsel_q[curr_category - 1].top() - reqs[i][0];
			waiting_time += diff;

			counsel_q[curr_category - 1].pop();
			counsel_q[curr_category - 1].push((reqs[i][0] + diff) + reqs[i][1]);
			
			continue;
		}

		counsel_q[curr_category - 1].push(reqs[i][0] + reqs[i][1]);
		counselors[curr_category - 1]--;
	}

	return waiting_time;
}

void select_counselor(int member, int idx, vector<int> &counselors, vector<vector<int>> &reqs) {
	if (member == 0) {
	    min_waiting_time = min(min_waiting_time, calculate_waiting_time(counselors, reqs));
		// 여기서 상담원 계산
		return;
	}

	for (int i = idx; i < counselors.size(); i++) {
		counselors[i]++;
		select_counselor(member - 1, i, counselors, reqs);
		counselors[i]--;
	}
}

int solution(int k, int n, vector<vector<int>> reqs) {
	int answer = 0;

	vector<int> counselors(k, 1);
	// 기본적으로 1씩 배치
	select_counselor(n - k, 0, counselors, reqs);

	answer = min_waiting_time;
	return answer;
}

int main() {
	solution(2, 3, { {5, 55, 2} , {10, 90, 2},{20, 40, 2},{50, 45, 2},{100, 50, 2}});
	return 0;
}
