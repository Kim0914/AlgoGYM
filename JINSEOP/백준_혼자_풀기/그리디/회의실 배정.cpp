#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int honey_road[100001];
int sum_arr[100001];
bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.second == b.second) // 끝나는 시간 기준 정렬
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	vector<pair<int, int>> room_list;
	int rooms = 0, start = 0, end = 0, room_cnt = 1;
	cin >> rooms;

	for (int i = 0; i < rooms; i++) {
		cin >> start >> end;
		room_list.push_back({ start, end });
	}

	sort(room_list.begin(), room_list.end(), cmp);

	int curr = room_list[0].second; // 가장 빨리 끝나는 회의 저장

	for (int i = 1; i < room_list.size(); i++) {
		if (curr <= room_list[i].first) { 
      // 가장 빨리 끝나는 회의 보다 다음 회의의 시작 시간이 더 크거나 같으면?
      // 겹치지 않고 가장 빨리 시작할 수 있는 회의!
			room_cnt++;
			curr = room_list[i].second;
		}
	}

	cout << room_cnt;
	return 0;
}
