#include <iostream>
#include <string>
using namespace std;

int num = 0, target_length = 0, answer = 0;
string target = "";
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> num;
	cin >> target_length;
	cin >> target;

	string cmp_str = "";
	int front_ptr = 0;
	for (int i = 0; i < target.size(); i++) {
		int ref_length = 0;
		// IOI인지 IOIOI인지 어디까지 검사했는가? 기준

		if (target[i] == 'O')
			continue; // O는 훑을 필요 없음
		else // I로 시작하면?
		{
			while (target[i + 1] == 'O' && target[i + 2] == 'I') {
				// IOI가 아니면 훑을 필요가 없음
				ref_length++; // IOIOI....
				if (ref_length == num) { // 입력한 길이와 같아지면
					ref_length--; // ref_length가 더 커지면 추가로 못셈
					answer++; // 일치하는 문자열이므로 답 증가
				}
				i += 2; // 다음 2칸을 훑는다. (IOI -> IOI를 찾아야 하므로)
			}
		}
		
	}
	
	cout << answer;
	return 0;
}
