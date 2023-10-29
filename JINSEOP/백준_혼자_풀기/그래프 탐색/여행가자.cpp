#include <iostream>
using namespace std;

int vertex = 0, planned_vertex = 0;
int city_map[201];
bool answer = true;
int get_parent(int node) {
	if (city_map[node] == node)
		return node;
	// 배열의 값이 본인이라면, 루트 노드라는 의미

	return city_map[node] = get_parent(city_map[node]);
	// 루트 노드가 아니라면, 재귀적으로 타고 들어간다
}

void do_union(int node_x, int node_y) {
	node_x = get_parent(node_x);
	node_y = get_parent(node_y);
	
	if (node_x > node_y) 
		// 통상적으로 값이 작은 쪽이 부모가 됨
		city_map[node_x] = node_y;
	else
		city_map[node_y] = node_x;
}

void init_map() {
	for (int i = 1; i <= vertex; i++)
		city_map[i] = i;
}

int main(){
	cin >> vertex >> planned_vertex;

	init_map();
	int connected = 0;
	for (int from = 1; from <= vertex; from++) {
		for (int to = 1; to <= vertex; to++) {
			cin >> connected;

			if (connected == 1)
				do_union(from, to);
		}
	}

	int start_city = 0, city = 0;
	for (int i = 0; i < planned_vertex; i++) {
		cin >> city;

		if (i == 0) // 첫 도시를 출발지로 (root)
			start_city = get_parent(city);
		else { 
			// 루트와 해당 도시의 부모가 다르다는 것은 다른 집합!
			// 즉, 둘은 연결되어있지 않다는 것!
			if (get_parent(city) != start_city) {
				answer = false;
				break;
			}
		}
	}

	if (answer)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
