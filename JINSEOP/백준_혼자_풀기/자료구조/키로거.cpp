#include <iostream>
#include <list>
using namespace std;

int tc;
string target;
int main() {
	cin >> tc;
	while (tc--) {
		list<char> keylogger;
		auto iter = keylogger.begin();
		// STL의 List를 이용해 연결리스트 사용 가능!

		cin >> target;
		for (char c : target) {
			if (c == '<') {
				if (iter != keylogger.begin())
					iter--;
			}
			else if (c == '>') {
				if (iter != keylogger.end())
					iter++;
			}
			// 커서에 따라 iterator를 움직임
			else if (c == '-'){
				if (iter != keylogger.begin())
					iter = keylogger.erase(--iter);
			// 바로 앞의 문자를 지우면, 지운 쪽으로 iterator 갱신
			}
			else
				keylogger.insert(iter, c);
		}

		for (char c : keylogger)
			cout << c;

		cout << '\n';
	}

	return 0; 
}
