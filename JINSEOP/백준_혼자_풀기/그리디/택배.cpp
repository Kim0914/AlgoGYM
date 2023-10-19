#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool custom_cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.second.first == b.second.first)
		return a.first < b.first;
	// tie break 시 출발지 기준 오름차순
	return a.second.first < b.second.first;
	// 도착지 기준 내림차순 정렬
	// 왜 도착지 기준으로 오름차순 정렬을 해야할까?
	// 택배를 빨리 내릴수록 효율적으로 공간을 사용할 수 있기 때문이다.
}

vector<pair<int, pair<int, int>>> parcel_info;
int num = 0, limit = 0, info_num = 0, src = 0, dest = 0, weight = 0, answer = 0;
int loads[2001];
int main(){
	cin >> num >> limit;
	cin >> info_num;
	for (int i = 0; i < info_num; i++) {
		cin >> src >> dest >> weight;
		parcel_info.push_back({ src, {dest, weight} });
	}

	sort(parcel_info.begin(), parcel_info.end(), custom_cmp);

	for (int i = 0; i < parcel_info.size(); i++) {
		src = parcel_info[i].first;
		dest = parcel_info[i].second.first;
		int weight = parcel_info[i].second.second;
		int max_loads = 0; // 택배가 마을을 지날 때 싣고있는 최대 무게

		for (int j = src; j < dest; j++)
			max_loads = max(max_loads, loads[j]);

		int capacity = min(weight, limit - max_loads);
		// 지금 가져가야 할 택배를 모두 실을 수 있는가?
		// 아니면 싣고있는 최대 무게 만큼 빼고 들고가야 하는가
		for (int j = src; j < dest; j++)
			loads[j] += capacity;
		// 해당 마을을 향할 때, 해당 용량만큼 택배를 실을 수 있다는 의미
		answer += capacity;
		// 성공적으로 트럭이 실어진 택배
	}

	cout << answer;
	return 0;
}
