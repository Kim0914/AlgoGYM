#include <iostream>
#include <unordered_map>
using namespace std;

int tc = 0, num = 0, team = 0;
int rank_counter[201][3];
int ranks[1001];
void init_arrays() {
	for (int i = 0; i <= num; i++) {
		ranks[i] = 0;
		for (int j = 0; j < 3; j++) {
			rank_counter[i][j] = 0;
		}
	}
}

int main(){
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int answer = 0, min_point = 100000000;
		unordered_map<int, int> member_counter;
		init_arrays();

		cin >> num;
		for (int i = 1; i <= num; i++) {
			cin >> team;
			member_counter[team]++;
			ranks[i] = team;
		}
		
		int rank_point = 1;
		for (int i = 1; i <= num; i++) {
			if (member_counter[ranks[i]] == 6) {
				if (rank_counter[ranks[i]][1] < 4) {
					rank_counter[ranks[i]][0] += rank_point;
					// 총점 계산
					rank_counter[ranks[i]][1]++;
					// 등장 횟수 계산
				}
				else if (rank_counter[ranks[i]][1] == 4) {
					rank_counter[ranks[i]][2] = rank_point;
					rank_counter[ranks[i]][1]++;
				}
				// 5등 점수 저장

				rank_point++;
			}
		}

		for (int i = 1; i <= member_counter.size(); i++) {
			if(member_counter[i] == 6){
				if (rank_counter[i][0] <= min_point) {
					if (rank_counter[i][0] == min_point) {
						if (rank_counter[i][2] < rank_counter[answer][2])
							answer = i;

						continue;
					}

					min_point = rank_counter[i][0];
					answer = i;
				}
			}
		}

		cout << answer << '\n';
	}

	return 0;
}
