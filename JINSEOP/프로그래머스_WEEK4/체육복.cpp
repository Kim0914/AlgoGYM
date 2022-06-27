#include <string>
#include <vector>
using namespace std;

int stud[31];
void init_arr(vector<int> lost, vector<int> reserve) {
	for (int i : reserve) stud[i]++;
	for (int i : lost) stud[i]--;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;
	init_arr(lost, reserve);

	for (int i = 1; i <= n; i++) {
		if (stud[i] == -1) {
			if (stud[i - 1] == 1) {
				stud[i]++; stud[i - 1]--;
			}
			else if (stud[i + 1] == 1) {
				stud[i]++; stud[i + 1]--;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (stud[i] == -1) answer--;
	return answer;
}
