#include <iostream>
#include <vector>
using namespace std;
#define OPTIMIZE ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int num = 0, parties = 0, knowers = 0, person = 0, party_members = 0;
int mst[51];
vector<int> know;
vector<int> graph[51];
int find_parent(int node) {
	if (mst[node] == node)
		return node;

	return mst[node] = find_parent(mst[node]);
}

void do_union(int node_x, int node_y) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);

	mst[node_y] = node_x;
}

void init_mst() {
	for (int i = 1; i <= num; i++)
		mst[i] = i;
}

bool check_parent(int node_x, int node_y) {
	node_x = find_parent(node_x);
	node_y = find_parent(node_y);

	if (node_x == node_y)
		return true;
	return false;
}

int main() {
	OPTIMIZE;

	cin >> num >> parties;
	cin >> knowers;
	for (int i = 0; i < knowers; i++) {
		cin >> person;
		know.push_back(person);
	}

	for (int i = 1; i <= parties; i++) {
		cin >> party_members;

		for (int j = 0; j < party_members; j++) {
			cin >> person;
			graph[i].push_back(person);
		}
	}
	
	init_mst();
	int answer = parties; // 원래 파티 수로 초기화
	for (int i = 1; i <= parties; i++)
		for (int j = 1; j < graph[i].size(); j++)
			do_union(graph[i][0], graph[i][j]);
	// 여기서 각 파티별로 사람을 묶는다.

	for (int i = 1; i <= parties; i++) {
	// 파티 전체를 돌며 갈 수 있는지 확인한다.
		bool can_go = true;
		for (int j = 0; j < graph[i].size(); j++) {
			if (!can_go)
				break;

			int participant = graph[i][j];
			for (int k = 0; k < know.size(); k++) {
				int knower = know[k];
				if (check_parent(participant, knower)) {
					can_go = false;
					break;
				}
			}
		}

		if (!can_go)
			answer--;
	}

	cout << answer; 
	return 0;
}
