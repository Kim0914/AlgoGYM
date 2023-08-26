#include <iostream>
using namespace std;

int tc = 0, num = 0, kids[20];
int main() {
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int result = 0;
		
		cin >> num;
		for (int i = 0; i < 20; i++) {
			cin >> kids[i]; // 20명 키 입력
		}

		for (int i = 0; i < 20; i++) {
			for (int j = i; j < 20; j++) {
				if (kids[i] > kids[j])
					// 현재 찍은 아이보다 작은 애들은 모두 앞으로 보내야함
					result++;
			}
		}

		cout << num << " " << result << '\n';
	}
}
