#include <iostream>
#include <vector>
using namespace std;

int num = 0, use_num = 0, use_wardrobe = 0, answer = 0;
pair<int, int> opened_wardrobe;
vector<int> to_use;
int main() {
	cin >> num;
	cin >> opened_wardrobe.first >> opened_wardrobe.second;
	cin >> use_num;
	for (int i = 0; i < use_num; i++) {
		cin >> use_wardrobe;
		
		if (abs(opened_wardrobe.first - use_wardrobe) < abs(opened_wardrobe.second - use_wardrobe)) {
			answer += abs(opened_wardrobe.first - use_wardrobe);
			opened_wardrobe.first = use_wardrobe;
		}
		else if (abs(opened_wardrobe.first - use_wardrobe) > abs(opened_wardrobe.second - use_wardrobe)) {
			answer += abs(opened_wardrobe.second - use_wardrobe);
			opened_wardrobe.second = use_wardrobe;
		}
	}

	cout << answer;
	return 0;
}
