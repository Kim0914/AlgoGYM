#include <iostream>
#include <algorithm>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

int num = 0, each_tree = 0, sum = 0, two_wc = 0;
int main() {
	OPTIMIZE;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> each_tree;
		
		sum += each_tree;
		two_wc += each_tree / 2;
		// 여기서 저장되는 건 각 나무에 사용할 수 있는 2의 개수
	}

	if (sum % 3 != 0) // 총합이 3의 배수가 아니면 일단 안된다.
		cout << "NO"; 
	else {
		if (two_wc >= sum / 3)
			cout << "YES";
		// 2의 개수가 SUM / 3 (걸리는 일수) 보다 크거나 같아야 함
		// 2의 개수가 같으면? 2와 1로 모두 해결이 가능하다는 의미
		// 걸리는 일수보다 많으면? 남은 2는 1을 모아서 해결할 수 있다는 의미
		else
			cout << "NO";
		// 걸리는 일수보다 적다는 것은, 해결할 수 없는 1이 존재한다는 의미이다.
	}

	return 0;
}
