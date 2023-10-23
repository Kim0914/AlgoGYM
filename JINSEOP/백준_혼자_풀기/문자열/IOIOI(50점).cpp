#include <iostream>
#include <string>
using namespace std;

int num = 0, target_length = 0, answer = 0;
string target = "", ref_str = "";
string generate_IOI() {
	string ref_str = "I";

	for (int i = 0; i < num; i++)
		ref_str += "OI";

	return ref_str;
}

int main(){
	cin >> num;
	cin >> target_length;
	cin >> target;

	ref_str = generate_IOI();
	string cmp_str = "";
	// 슬라이딩 윈도우로 풀어보자
	int front_ptr = 0;
	for (int rear_ptr = 0; rear_ptr < target.size(); rear_ptr++) {
		while (cmp_str.size() != ref_str.size()) {
			cmp_str += target[front_ptr];
			front_ptr++;
		// 하나씩 글자를 채워보자
		}

		if (front_ptr == target.size())
			break;

		if (cmp_str == ref_str)
			answer++;
		cmp_str = cmp_str.substr(1);
	}
	
	cout << answer;
	return 0;
}
