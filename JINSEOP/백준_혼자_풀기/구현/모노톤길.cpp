#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

int tc = 0, cafe_num = 0, cafe_x = 0, cafe_y = 0, query_num = 0, query = 0;
int main(){
	cin >> tc;

	while (tc--) {
		vector<pii> cafe_list;
		cin >> cafe_num;

		for (int i = 0; i < cafe_num; i++) {
			cin >> cafe_x >> cafe_y;
			cafe_list.push_back({ cafe_x, cafe_y });
		} // 카페 입력 후 정렬
		sort(cafe_list.begin(), cafe_list.end());
		// 기본적으로 x축 오름차순 -> y축 오름차순
		
		int idx = 1;
		if (cafe_list[0].second != 0) {
		// 시작점의 y좌표가 0이 아니면 잘못된 경우
			while (cafe_list[idx - 1].first == cafe_list[idx].first)
				idx++;

			reverse(cafe_list.begin(), cafe_list.begin() + idx);
			// x축이 0인 부분을 뒤집어야함
		}

		for (int i = idx; i < cafe_num; i++) {
		// 뒤집은 부분부터 시작, 잘못되지 않았으면 1부터 그냥 출발
			if (cafe_list[i - 1].first != cafe_list[i].first) {
			// x좌표가 다른데, y좌표도 다르면? 잘못된 경로
				if (cafe_list[i - 1].second != cafe_list[i].second) {
					int length_to_reverse = 1;
					while (cafe_list[i + length_to_reverse - 1].first == cafe_list[i + length_to_reverse].first) {
						length_to_reverse++;

						if (i + length_to_reverse >= cafe_num)
							break;
					}
					// 동일한 x좌표의 길이를 계산 후 그만큼 뒤집어 주자

					reverse(cafe_list.begin() + i, cafe_list.begin() + i + length_to_reverse);
				}
			}
		}

		cin >> query_num;
		for (int i = 0; i < query_num; i++) {
			cin >> query;
			cout << cafe_list[query - 1].first << " " << cafe_list[query - 1].second << '\n';
		} // 질의 응답
	}

	return 0;
}
