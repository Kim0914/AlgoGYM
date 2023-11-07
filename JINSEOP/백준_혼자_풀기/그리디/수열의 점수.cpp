#include <iostream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define ll long long

ll num = 0, digit = 0, answer = 0;
unordered_map<string, int> pos_neg_classifier;
vector<ll> seq;
deque<ll> last_dq;
void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

void classify(ll digit) {
	if (digit < 0)
		pos_neg_classifier["NEG"]++;
	if (digit == 0)
		pos_neg_classifier["ZERO"]++;
	if (digit > 0)
		pos_neg_classifier["POS"]++;
}

int main(){
	optimize();
	cin >> num;
	for(int i = 0; i < num; i++){
		cin >> digit;
		seq.push_back(digit);
		classify(digit);
	}

	sort(seq.begin(), seq.end());
	// 오름차순 정렬

	for (int i = 0; i < num; i += 2) {
		if (pos_neg_classifier["NEG"] == 0)
			break; // 음수가 더 이상 없으면 중지
		if (pos_neg_classifier["NEG"] == 1) {
			last_dq.push_front(seq[i]);
			break; // 하나 남은 음수는 큐에 넣고 중지
		}

		answer += (seq[i] * seq[i + 1]);
		pos_neg_classifier["NEG"] -= 2;
		// 음수 2개씩 차감 해주어야 함
	}

	for (int i = num - 1; i >= 0; i -= 2) {
		if (pos_neg_classifier["POS"] == 0)
			break; // 양수가 더 이상 없으면 중지
		if (pos_neg_classifier["POS"] == 1) {
			last_dq.push_back(seq[i]);
			break; // 하나 남은 양수는 큐에 넣고 중지
		}

		if (seq[i - 1] == 1) {
			answer += (seq[i] + seq[i-1]);
			pos_neg_classifier["POS"] -= 2;
			// 1은 i-1번째에 올 수 밖에 없음.
			// 양수 입장에서 1은 더하는게 이득
		}
		else {
			answer += (seq[i] * seq[i - 1]);
			pos_neg_classifier["POS"] -= 2;
		}
		// 양수 2개씩 차감 해주어야 함
	}

	// 이제 남은 큐에서 분기를 통해 정리할 차례
	if (pos_neg_classifier["NEG"] == 1) {
		if (pos_neg_classifier["ZERO"] == 1) {
			pos_neg_classifier["NEG"]--;
			pos_neg_classifier["ZERO"]--;
			last_dq.pop_front();
			// 0이 있으면 음수랑 곱하면 최대임
		}
		else {
			answer += last_dq.front();
			last_dq.pop_front();
			// 0이 없으면 그냥 더해야함 어쩔 수 없음
			pos_neg_classifier["NEG"]--;
		}
	}

	if (pos_neg_classifier["POS"] == 1) {
		answer += last_dq.back();
		last_dq.pop_back();
		// 양수는 그냥 더해주는게 최대임
		pos_neg_classifier["POS"]--;
	}

	cout << answer;
	return 0;
}
