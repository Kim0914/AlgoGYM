#include <iostream>
#include <vector>
using namespace std;

int num = 0, channel_num = 0, initial_channel = 0, fav = 0, hate = 0, answer = 0;
int channels[100001]; // 채널을 이동할 인접 행렬
bool visit[100001];
void dfs(int idx) {
	visit[idx] = true; // 이미 봤던 채널

	if (channels[idx] == 0) // 더 이상 불만이 없으면 종료
		return;
	if (visit[channels[idx]] == true) {
		answer = -1; // 이미 봤던 채널로 돌아오면 싸이클 존재
		return;
	}

	answer++; // 위의 조건에 모두 안걸리면 채널 변경
	dfs(channels[idx]);
}

int main() {
	cin >> num >> channel_num >> initial_channel;
	// 이 문제는 Cycle이 존재하면 -1을 반환하면 된다.
	for (int i = 0; i < num; i++) {
		cin >> fav >> hate;

		if(channels[hate] == 0) // 비어있으면 저장
			channels[hate] = fav;
	}

	dfs(initial_channel); // 현재 채널에서 시작한다.
	cout << answer;
	return 0;
}
