#include <iostream>
#include <deque>
using namespace std;

int num = 0, rm_num = 0, iter = 0;
string target = "", answer = "";
int main() {
	cin >> num >> rm_num;
	cin >> target;

	deque<char> validator;
  // 자료구조로 덱을 채용한다.
  // 왜? 앞뒤로 뺄 수 있어야 편함
  
	while (iter < target.size()) {
		while (rm_num != 0 && !validator.empty() && (validator.back() < target[iter])) {
      // rm_num 만큼 수를 지워야 한다.
      // 그러므로, rm_num이 아직 남아있고 덱이 비어있지 않은지 먼저 검사한다.
      // 그 상태에서 만약 덱의 끝이 새로 추가할 숫자보다 작다면?
      // 현재 덱에 들어있는 수는 사용할 필요가 없다고 판단하고 빼낸다.
			validator.pop_back();
			rm_num--;
      // 빼냈다는 것은 수를 지웠다는 것이므로, rm_num을 하나 지운다.
		}

		validator.push_back(target[iter]);
		iter++;
    // 기본적으로 덱에 목표하는 숫자를 집어 넣는다.
    // 주의할 점은 앞에서 부터 훑어야 한다!
	}

	while (rm_num--)
    // 위의 로직에서 iterator를 target의 크기만큼 돌았는데
    // 지우기로 목표한 수만큼 지우지 못했다면?
    // 그 말은, 뒤로 갈수록 점점 수가 작아진다는 의미가 된다.
    // 따라서 뒤에서부터 남은 rm_num 만큼 수를 지워준다.
		validator.pop_back();

	while (!validator.empty()) {
		cout << validator.front();
		validator.pop_front();
    // 이 부분이 덱을 쓴 가장 큰 이유이다.
    // 우리가 앞에서부터 탐색해서 넣었기 때문에, 스택을 사용하면 수가 뒤집어진다.
    // 따라서 덱을 사용해서 앞에서부터 출력해주도록 하자.
	}

	return 0;
}
