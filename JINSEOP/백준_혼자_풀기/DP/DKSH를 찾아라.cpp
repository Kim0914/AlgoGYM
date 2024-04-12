#include <iostream>
using namespace std;
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define ll long long

int length = 0;
string target = "";
int main() {
	OPTIMIZE;

	cin >> length >> target;

	ll d_cnt = 0, k_cnt = 0, s_cnt = 0, h_cnt = 0;
	for (int i = 0; i < target.size(); i++) {
		if (target[i] == 'D')
			d_cnt++;
		else if (target[i] == 'K')
			k_cnt += d_cnt;
		else if (target[i] == 'S')
			s_cnt += k_cnt;
		else if (target[i] == 'H')
			h_cnt += s_cnt;
	} 
  // D에서부터 차례대로 쌓아나간다.
  // DDFEEKKSSWEHHH 라고 생각해보자.
  // 처음 K를 만날 땐, 앞에 D가 2개 있었으니 2가 더해진다.
  // 다음 K를 만날 땐, 앞에 D가 또 2개있었으니 2가 더해져 총 4가 된다.
  // D 2개와 K 2개를 통해 만들 수 있는 DK의 종류는 4개이기 때문이다.

  // 위와 동일한 원리로, 뒤에 계속 더해나가면 마지막 H에는 결국 16이 저장된다.
  // D D K K S S H H이기 때문에, 옳은 답임을 알 수 있다.
	cout << h_cnt;
	return 0;
}
