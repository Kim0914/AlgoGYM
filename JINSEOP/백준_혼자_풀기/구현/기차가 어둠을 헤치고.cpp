#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int num = 0, cmd_num = 0;
vector<string> train_station;
unordered_set<string> train_report;
void optimize() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void push_passenger(int target) {
	for (int i = train_station[target].size() - 1; i >= 1; i--)
		train_station[target][i] = train_station[target][i - 1];

	train_station[target][0] = 'O';
}

void pull_passenger(int target) {
	for (int i = 0; i < train_station[target].size() - 1; i++)
		train_station[target][i] = train_station[target][i + 1];

	train_station[target][train_station[target].size() - 1] = 'O';
}

int main() {
	optimize();

	cin >> num >> cmd_num;
	for (int i = 0; i < num; i++)
		train_station.push_back("OOOOOOOOOOOOOOOOOOOO");

	int cmd = 0, target = 0, seat = 0;
	for (int i = 0; i < cmd_num; i++) {
		cin >> cmd >> target;
		switch (cmd)
		{
		case 1:
			cin >> seat;
			train_station[target - 1][seat - 1] = 'X';
			// occupied
			break;
		case 2:
			cin >> seat;
			train_station[target - 1][seat - 1] = 'O';
			// vacant
			break;
		case 3:
			push_passenger(target - 1);
			break;
		case 4:
			pull_passenger(target - 1);
			break;
		}
	}
	// 기차 자리 등록

	int answer = 0;
	for (int i = 0; i < train_station.size(); i++)
		train_report.insert(train_station[i]);
	// 기차 보내기

	cout << train_report.size();
	return 0;
}
