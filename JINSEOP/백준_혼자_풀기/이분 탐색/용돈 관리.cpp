#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int day = 0, withdraw = 0, expense_per_day = 0, whole_expense = 0, answer = INT32_MAX;
int expense_list[100001];
int main(){
	cin >> day >> withdraw;
	for (int i = 0; i < day; i++) {
		cin >> expense_per_day;
		whole_expense += expense_per_day;
		expense_list[i] = expense_per_day;
	}

	int left = 1, right = whole_expense; // 이분 탐색
	int leftover = 0; // 인출할 수 있는 금액 중 남은 돈
	while (left <= right) {
		int mid = (left + right) / 2;
		leftover = mid; // 인출 금액 초기화

		bool vacant = false;
		// 인출한 금액에 대해 돈이 부족하지 않은가?
		int withdraw_count = 1;
		// 인출 횟수
		for (int i = 0; i < day; i++) {
			if (expense_list[i] > mid) {
				// 인출 금액보다 지출이 많아지면 바로 중지
				vacant = true;
				break;
			}
			if (expense_list[i] > leftover) {
				// 인출 금액보다 지출이 적으면 돈이 남는다
				leftover = mid;
				// 사용할 수 있는 금액 초기화
				withdraw_count++;
				// 인출 횟수 증가
			}

			leftover -= expense_list[i];
		}

		if (vacant || withdraw_count > withdraw) {
			// (인출 금액 < 지출)이거나 인출 횟수가 더 많아진 경우
			left = mid + 1;
		}
		else {
			answer = min(answer, mid);
			right = mid - 1;
		}
	}

	cout << answer;
	return 0;
}
