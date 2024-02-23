#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;
#define piii pair<pair<int, int>, int>

struct cmp {
	bool operator()(piii a, piii b) {
		if (a.first.first == b.first.first)
			return a.second > b.second;
		
		return a.first.first > b.first.first;
	}
};

unordered_map<int, int> core_index_map;
int solution(int n, vector<int> cores) {
	int answer = 0;
	int size = cores.size(), iter = 0;

	for (int i = 0; i < size; i++)
		core_index_map[cores[i]] = i + 1;
	sort(cores.begin(), cores.end());

	priority_queue<piii, vector<piii>, cmp> core_q;
	for (int i = 0; i < cores.size(); i++) {
		core_q.push({ { cores[i], cores[i] }, i });
		iter = i;
	}

	int timer = 1;
	bool finished = false;
	while (true) {
		while (!core_q.empty() && (core_q.top().first.first == timer)) {
			iter++;
			core_q.push({ { timer + core_q.top().first.second, core_q.top().first.second}, iter });
			n--;

			cout << core_q.top().first.first << " " << core_q.top().first.second << " " << core_q.top().second << '\n';

			if (n == 0) {
				finished = true;
				answer = core_q.top().first.second;
				break;
			}

			core_q.pop();
		}

		if (finished)
			break;

		timer++;
	}

	answer = core_index_map[answer];
	return answer;
}
