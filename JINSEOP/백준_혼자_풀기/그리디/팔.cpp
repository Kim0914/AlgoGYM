#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

string r = "", l = "";
int main()
{
	cin >> r >> l;
	// 1 ~ 2,000,000,000 다 훑으면 시간 초과

	int answer = 0;
	if (r.size() != l.size()) {
	// 자릿 수가 다른 경우엔 무조건 0임
		answer = 0;
	}
	else {
	// 자릿 수가 같아지면 앞에서 부터 훑어야 한다.
		for (int i = 0; i < r.size(); i++) {
			if (r[i] == '8' && l[i] == '8')
				answer++;
			// 둘 다 8로 같으면 8밖에 못옴
			
			if (r[i] != l[i])
				break;
			// 그럼 둘이 숫자가 다른 경우엔?
			// 반드시 중간에 8이 필요없는 수가 오게 된다.
		}
	}

	cout << answer;
	return 0;
}
