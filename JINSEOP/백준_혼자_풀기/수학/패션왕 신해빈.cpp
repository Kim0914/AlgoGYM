#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int tc = 0, num = 0;
string name = "", kind = "";
int main() {
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		unordered_map<string, int> cloth_map;
		int answer = 1;
		cin >> num;

		for (int j = 0; j < num; j++) {
			cin >> name >> kind;
			cloth_map[kind]++;
		} // 종류별 옷 수를 맵에 저장
		
		for (auto cloth : cloth_map) // 옷 가지 수 + 안입는 경우를 곱해 줌
			answer *= (cloth.second + 1); // 그럼 모든 경우의 수가 나오는데

		cout << answer - 1 << '\n'; // 아예 안입는 경우만 빼줌
	}
	return 0;
}
