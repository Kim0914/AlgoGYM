#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int row = 0, stud = 0, liked_stud = 0;
vector<int> like_state[401];
vector<int> student_sequence;
int classroom[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
pair<int, int> check_favorite(int curr_x, int curr_y, int curr) {
	int favor_cnt = 0;
	int vacant_cnt = 0;

	for (int i = 0; i < 4; i++) {
		int nx = curr_x + dx[i];
		int ny = curr_y + dy[i];

		if ((nx >= 0 && nx < row) && (ny >= 0 && ny < row)) {
			for (int j = 0; j < 4; j++)
				if (like_state[student_sequence[curr]][j] == classroom[nx][ny])
					favor_cnt++;

			if (classroom[nx][ny] == 0)
				vacant_cnt++;
		}
	}

	return { favor_cnt, vacant_cnt };
}

int count_favorite() {
	int favor_score = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			int favor_cnt = 0;

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if ((nx >= 0 && nx < row) && (ny >= 0 && ny < row)) {
					for (int h = 0; h < 4; h++)
						if (like_state[classroom[i][j]][h] == classroom[nx][ny])
							favor_cnt++;
				}
			}

			if (favor_cnt == 0)
				continue;

			favor_score += pow(10, favor_cnt - 1);
		}
	}

	return favor_score;
}

int main() {
	cin >> row;
	for (int i = 0; i < row * row; i++) {
		cin >> stud;
		student_sequence.push_back(stud);

		for (int i = 0; i < 4; i++) {
			cin >> liked_stud;
			like_state[stud].push_back(liked_stud);
		}
	} // 인접리스트 형태로 좋아하는 학생 목록 저장

	for (int target_stud = 0; target_stud < student_sequence.size(); target_stud++) {
		pair<int, int> count_set;
		pair<int, int> best_set;
		int best_x = row - 1, best_y = row - 1;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < row; j++) {
				if (classroom[i][j] != 0)
					continue; // 이미 앉은 자리는 못 앉음

				count_set = check_favorite(i, j, target_stud);
				
				if (best_set.first < count_set.first) {
					best_x = i; best_y = j;
					best_set = count_set;
				}
				else if (best_set.first == count_set.first) {
					if (best_set.second < count_set.second) {
						best_x = i; best_y = j;
						best_set = count_set;
					}
					else if (best_set.second == count_set.second)
						if (best_x > i) {
							best_x = i;
							best_y = j;
						}
						else if (best_x == i) {
							if (best_y > j) {
								best_x = i;
								best_y = j;
							}
						}
				}
			}
		}

		classroom[best_x][best_y] = student_sequence[target_stud];
	}

	cout << count_favorite();
	return 0;
}
