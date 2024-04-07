#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0, statue = 0, statue_v = 0;
int dp[100001], statues[100001];
int main(){
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> statue;
		if (statue == 2)
			statues[i] = -1;
		else
			statues[i] = 1;
	} // 누적합을 계산하기 위해, 오른쪽 석상을 -1로 치환

	dp[0] = statues[0];
	for (int i = 1; i < num; i++)
		dp[i] = dp[i - 1] + statues[i];
  // 누적합을 계산해놓는다.
  
	int max_left_statue = *max_element(dp, dp + num);
	int max_right_statue = *min_element(dp, dp + num);
  // 그럼 최대값과 최솟값을 계산해서 답에 이용할 수 있다.
  // 누적합에서 최대값이라 함은, 연속해서 왼쪽으로 보고있는 석상을 칠할 때 얻는 최대값이다.
  // 최소값이라 함은, 연속해서 오른쪽으로 보고있는 석상을 칠할 때 얻는 최대값이다.

  // 예를 들어, 1 1 1 1 2 2 2 2 2 2 1 1와 같이 석상이 배치되어있다.
  // 이 때, 누적합을 계산하면 최대값은 4, 최소값은 -2가 될 것이다.
  // 그럼 정답은 4-(-2)를 한 6이 된다.
  // 최소값이 -2가 나왔다는 것은, 1보다 2가 2번 더 많이 나왔다는 의미이다.
  // 그런 상황에서 1의 최대값이 4였으면, 4보다 2회 더 나온 6이 답이 되는 것이다.
  
	if (max_left_statue <= 0)
		max_left_statue = 0;
	if (max_right_statue >= 0)
		max_right_statue = 0;
  // 이 부분이 중요하다.
  // 절대 왼쪽 석상이 음수가 되거나 오른쪽 석상이 양수가 되어서는 안된다.
  // 그 이유는 단 한번도 1이 2를 역전한 적이 없고, 2가 1을 역전한 적이 없다는 말이니
  // 연속된 최대값 만을 답으로 사용하거나 최소값 만을 답으로 사용해야 한다.

  // 예를 들어 1 1 1 1 1 2 2 의 경우
  // 최대값 5 최소값 3이 된다. ==> 원래 하듯이 5 - 3을 하는 것은 오답이다.
  // 항상 1이 더 많았기 때문에, 1만 가져가면 되는 것이다.
  
	cout << max_left_statue - max_right_statue;
	return 0;
}
