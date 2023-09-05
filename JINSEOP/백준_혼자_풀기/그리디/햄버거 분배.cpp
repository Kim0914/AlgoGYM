#include <iostream>
#include <vector>
using namespace std;

int num = 0, boundary = 0, answer = 0;
string hamburgers;
void search_hamburger(int idx) { // 바운더리 만큼
	for (int i = idx - boundary; i <= idx + boundary; i++) {
		if (i >= 0) {
			if (hamburgers[i] == 'H') {
				hamburgers[i] = 'X';
				answer++;
				break;
			}
		}
	}
}

int main() {
	cin >> num >> boundary;
	cin >> hamburgers;

	for (int i = 0; i < hamburgers.size(); i++)
		if (hamburgers[i] == 'P')
			// 주변 훑기
			search_hamburger(i);

	cout << answer;
	return 0;
}
