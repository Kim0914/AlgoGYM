#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000

int num = 0, from = 0, to = 0;
int friend_book[51][51];
vector<int> candidate;
void init_book() {
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			if (i == j)
				continue;
			friend_book[i][j] = INF;
		}
	}
}

void floyd_warshall() {
	for (int mid = 1; mid <= num; mid++) {
		for (int i = 1; i <= num; i++) {
			for (int j = 1; j <= num; j++) {
				if (i == j)
					continue;
				if (friend_book[i][mid] != INF && friend_book[mid][j] != INF)
					friend_book[i][j] = min(friend_book[i][mid] + friend_book[mid][j], friend_book[i][j]);
			}
		}
	}

	// Floyd-Warshall 알고리즘을 통해 관계 정립
}

int count_candidate() {
	int candidate_score = INF;
	for (int i = 1; i <= num; i++) {
		int partial_max = 0;

		for (int j = 1; j <= num; j++) {
			if (i == j)
				continue;
			partial_max = max(friend_book[i][j], partial_max);
		}

		candidate_score = min(candidate_score, partial_max);
	}

	for (int i = 1; i <= num; i++) {
		int partial_max = 0;

		for (int j = 1; j <= num; j++) {
			if (i == j)
				continue;
			partial_max = max(friend_book[i][j], partial_max);
		}

		if (partial_max == candidate_score)
			candidate.push_back(i);
	}

	return candidate_score;
}

int main() {
	cin >> num;

	init_book();
	while (true) {
		cin >> from >> to;
		friend_book[from][to] = 1;
		friend_book[to][from] = 1;
		// 둘이 친구라는 뜻

		if (from == -1 && to == -1)
			break;
	}

	floyd_warshall();

	cout << count_candidate() << " ";
	cout << candidate.size() << '\n';
	for (auto i : candidate)
		cout << i << " ";

	return 0;
}
