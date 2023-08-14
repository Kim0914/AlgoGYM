#include <iostream>
#include <vector>
using namespace std;

int num = 0, bigger = 0;
int main() {
	cin >> num;
	vector<int> line;
	vector<int> real_line(num, 0);
	
	line.push_back(0);
	for (int i = 0; i < num; i++) {
		cin >> bigger;
		line.push_back(bigger);
	}

	for (int i = 1; i <= num; i++) {
		int ptr = 0; // 어느 위치에 설 것인지?

		while (line[i] != 0) { // 위치 찾기
			if(real_line[ptr] == 0)
				line[i]--; // 자리에 사람이 이미 있으면 지나가야 함
			ptr++; // 이게 가능한 이유는, 이미 있는 사람은 본인보다 작을 것이기 때문
		}

		while (real_line[ptr] != 0)
			ptr++; // 다 지나가도 사람이 있으면 더 넘어가야함

		real_line[ptr] = i; // 최종 위치
	}

	for (int i = 0; i < num; i++)
		cout << real_line[i] << " ";

	return 0;
}
