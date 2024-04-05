#include <iostream>
#include <vector>
using namespace std;

int src_num = 0;
string dest = "";
vector<string> src_vec;
bool dp[101];
int main(){
	cin >> dest;
	cin >> src_num;

	string src = "";
	for (int i = 0; i < src_num; i++) {
		cin >> src;
		src_vec.push_back(src);
	}

	for (int i = 0; i < dest.size(); i++) {
		if (dp[i] || i == 0) {
		// 만들어야 하는 문자열이거나 처음 시작일 때 진행
			int start = i;

			for (int j = 0; j < src_vec.size(); j++) {
				bool can_make = true;
				for (int k = 0; k < src_vec[j].size(); k++) {
				// 모든 단어를 순회하며 만들 수 있는지 체크한다.
				// 이 과정에서 최대 100 * 100 * 100 = 100만 밖에 소요 안됨
					if (src_vec[j][k] != dest[start + k]) {
						can_make = false;
						break; // 문자가 다르면 즉시 중지
					}
				}

				if (can_make)
					dp[start + src_vec[j].size()] = true;
				// 문자열을 만약 만들었으면 그 다음칸에 표시 해야함
			}
		}
	}

	cout << dp[dest.size()];
	return 0;
}
