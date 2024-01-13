#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<string> checklist;
int string_to_time(string target) {
	string temp_h = target.substr(0, 2);
	string temp_m = target.substr(3, 2);

	return stoi(temp_h) * 60 + stoi(temp_m);
}

int main() {
	string start_time = "", end_time = "", end_stream_time = "";
	cin >> start_time >> end_time >> end_stream_time;

	int start = string_to_time(start_time);
	int end = string_to_time(end_time);
	int quit = string_to_time(end_stream_time);
	int answer = 0;

	string chat_time = "", nickname = "";
	while (cin >> chat_time >> nickname) {
		int chat = string_to_time(chat_time);

		if (chat <= start)
			checklist.insert(nickname);
		// 명부에 집어 넣음, 입장

		if (chat >= end && chat <= quit) {
			if (checklist.find(nickname) != checklist.end()) {
				answer++;
				checklist.erase(nickname);
			}
		}
		// 퇴장한 학생들
	}

	cout << answer;
	return 0;
}
