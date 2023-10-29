#include <iostream>
#include <vector>
using namespace std;
#define INF 100000000

int bacon_map[101][101];
int vertex = 0, edge = 0, from = 0, to = 0, answer = 0;
void init_bacon() {
	for (int i = 1; i <= vertex; i++) {
		for (int j = 1; j <= vertex; j++) {
			if (i == j) // 자기자신은 제외
				continue;
			bacon_map[i][j] = INF;
		}
	}
}

void floyd_warshall() {
	for (int mid = 1; mid <= vertex; mid++) {
		for (int i = 1; i <= vertex; i++) {
			for (int j = 1; j <= vertex; j++) {
				if (i == j) // 자기자신과의 관계는 없음
					continue;
				bacon_map[i][j] = min(bacon_map[i][j], bacon_map[i][mid] + bacon_map[mid][j]);
				// 최단 경로를 탐색하기 때문에, 최소 값으로 유지
			}
		}
	}
}

void calculate_kevin_bacon() {

}

int main(){
	cin >> vertex >> edge;

	init_bacon();
	for (int i = 0; i < edge; i++) {
		cin >> from >> to;

		bacon_map[from][to] = 1;
		bacon_map[to][from] = 1;
		// Floyd-Warshall을 위해 인접 행렬 생성
		// 친구간의 거리는 무조건 1이다.
	}

	floyd_warshall();
	// 이제 인접 행렬의 각 칸이 의미하는 바가 무엇일까?
	// bacon[x][y]는 x가 y를 알기까지 걸리는 거리를 의미한다.

	int min_of_sum = INF;
	for (int i = 1; i <= vertex; i++) {
		int partial_sum = 0;
		// 1번 친구 부터 베이컨 수 계산

		for (int j = 1; j <= vertex; j++)
			partial_sum += bacon_map[i][j];
		// 1번 친구부터 나머지 친구들까지의 거리

		if (min_of_sum > partial_sum) {
			min_of_sum = partial_sum;
			answer = i; 
			// 현재 가리키고 있는 사람이 최소 베이컨 수를 가짐
		}
	}

	cout << answer;
	return 0;
}
