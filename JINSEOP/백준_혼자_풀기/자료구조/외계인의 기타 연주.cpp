#include <iostream>
#include <stack>
using namespace std;

int num = 0, prats = 0;
stack<int> guitar[7];
int main()
{
	cin >> num >> prats;

	int line = 0, prat = 0, move_count = 0;
	for (int i = 0; i < num; i++) {
		cin >> line >> prat;
		
		bool pass = false;
		while (!guitar[line].empty() && prat <= guitar[line].top()) {
			if (guitar[line].top() == prat) {
				pass = true;
				break;
			}

			guitar[line].pop();
			move_count++; // 손 뗄때 추가
		}

		if (pass)
			continue;

		guitar[line].push(prat); // 기타는 줄이 6개!
		move_count++; // 누를 때 추가
	}

	cout << move_count;
	return 0;
}
