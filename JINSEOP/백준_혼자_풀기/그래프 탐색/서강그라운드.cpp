#include <iostream>
using namespace std;
#define INF 30

int game_map[101][101], item_info[101];
int vertex = 0, range_limit = 0, edge = 0, from = 0, to = 0, cost = 0;
void init_map() {
	for (int i = 1; i <= vertex; i++) {
		for (int j = 1; j <= vertex; j++) {
			if (i == j)
				continue;
			game_map[i][j] = INF;
		}
	}
}

void floyd_warshall(){
	for (int mid = 1; mid <= vertex; mid++) {
		for (int i = 1; i <= vertex; i++) {
			for (int j = 1; j <= vertex; j++) {
				if (i == j)
					continue;
				game_map[i][j] = min(game_map[i][mid] + game_map[mid][j], game_map[i][j]);
			}
		}
	}
}

int calculate_point() {
	int max_point = 0;
	for (int i = 1; i <= vertex; i++) {
		int sum = 0;

		for (int j = 1; j <= vertex; j++) {
			if (game_map[i][j] <= range_limit)
				sum += item_info[j];
		}

		max_point = max(max_point, sum);
	}

	return max_point;
}

int main() {
	cin >> vertex >> range_limit >> edge;

	init_map();
	for (int i = 1; i <= vertex; i++)
		cin >> item_info[i];
	for (int i = 0; i < edge; i++) {
		cin >> from >> to >> cost;
		game_map[from][to] = cost;
		game_map[to][from] = cost;
	}

	floyd_warshall();
	cout << calculate_point();

	return 0;
}
