#include <string>
#include <vector>
using namespace std;

vector<pair<int, int>> divisors;
void find_divisor(int brown, int yellow) {
	int target = brown + yellow;
	int idx = target;
	bool is_stop = false;

	for (int i = 1 ; i < target ; i++) {
		if (is_stop) break;
		for (int j = idx; j > 0; j--) {
			if (i > j) { break; }
			if (i * j == target) {
				if (i > j) { is_stop = true; break; }
				idx = j;
				divisors.push_back({ i, j });
				break;
			}
		}
	}
}

vector<int> find_accurate(int brown, int yellow) {
	vector<int> answer(2, 0);

	for (auto div : divisors) {
		if ((div.first - 2) * (div.second - 2) == yellow) {
			answer[1] = div.first; answer[0] = div.second;
			return answer;
		}
	}
}

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	find_divisor(brown, yellow);
	answer = find_accurate(brown, yellow);

	return answer;
}
