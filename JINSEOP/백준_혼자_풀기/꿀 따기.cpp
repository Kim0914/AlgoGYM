#include <iostream>
#include <vector>
using namespace std;

int honey_road[100001];
int sum_arr[100001];
int main() {
	int dist = 0, result = 0, honey = 0;
	cin >> dist;

	for (int i = 1; i <= dist; i++) {
		cin >> honey_road[i];
		sum_arr[i] = sum_arr[i - 1] + honey_road[i]; // 누적 합 계산
	}

	for (int i = 2; i < dist; i++) { // 벌 - 꿀통 - 벌 순서로 놓는 경우
		honey = (sum_arr[i] - sum_arr[1]) + (sum_arr[dist - 1] - sum_arr[i - 1]);
		result = max(result, honey);
	}

	for (int i = 2; i < dist; i++) { // 벌 - 벌 - 꿀통 순서로 놓는 경우
		honey = (sum_arr[dist] - sum_arr[1] - honey_road[i]) + (sum_arr[dist] - sum_arr[i]);
		result = max(result, honey);
	}

	for (int i = 2; i < dist; i++) {
		honey = (sum_arr[dist - 1] - honey_road[i]) + sum_arr[i-1];
		result = max(result, honey);
	}

	cout << result;

	return 0;
}

![법러](https://github.com/Kim0914/AlgoGYM/assets/71700079/cea6f740-b4e5-4e10-88fb-611a660c1eea)  
