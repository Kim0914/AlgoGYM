#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> car_input;
int car_output[1001];
int num = 0, answer = 0;
string car_num = "";
int main(){
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> car_num;
		car_input[car_num] = i + 1;
		// 차가 들어온 순서를 모두 알고 있어야 함
	}

	for (int i = 0; i < num; i++) {
		cin >> car_num;
		car_output[i+1] = car_input[car_num];
		// 나간 순서도 저장해주자
	}

	for (int i = 1; i < num; i++) {
		for (int j = i + 1; j < num+1; j++) {
			if (car_output[i] > car_output[j]) {
				answer++;
				break;
        // 차가 나간순서대로 훑는데, 자기보다 뒤에있는 차가 자기보다 빨리 들어왔다면?
        // 추월한 것!
			}
		}
	}
	cout << answer;
	return 0;
}
