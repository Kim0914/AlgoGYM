#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int pl_num = 0, limit = 0, level = 0;
string username = "";
struct cmp {
	bool operator()(pair<int, string>& a, pair<int, string>& b) {
		return a.second > b.second;
	}
};

vector<priority_queue<pair<int, string>, vector<pair<int, string>>, cmp>> room_list;
int main() {
	priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> init_q;
	cin >> pl_num >> limit;
	for (int i = 0; i < pl_num; i++) {
		int iter = 0;
		cin >> level >> username;

		if (i == 0) {
			init_q.push({ level, username });
			room_list.push_back(init_q);
		}
		else {
			while (((level > room_list[iter].top().first + 10) || (level < room_list[iter].top().first - 10))
					|| room_list[iter].size() >= limit) {
				iter++;

				if (iter > room_list.size() - 1)
					break;
			}

			if (iter > room_list.size() - 1) {
				priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> added_q;
				added_q.push({ level, username });
				room_list.push_back(added_q);
			}
			else
				room_list[iter].push({ level, username });
		}
	}

	for (int i = 0; i < room_list.size(); i++) {
		if (room_list[i].size() >= limit)
			cout << "Started!" << '\n';
		else
			cout << "Waiting!" << '\n';

		while (!room_list[i].empty()) {
			cout << room_list[i].top().first << " " << room_list[i].top().second << '\n';
			room_list[i].pop();
		}
	}

	return 0;
}
