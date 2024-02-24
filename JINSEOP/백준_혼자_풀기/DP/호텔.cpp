#include <iostream>
#include <vector>
using namespace std;
#define pii pair<int, int>
#define INF 987654321

int goal = 0, num = 0, cost = 0, increased_pop = 0;
int pops[1001];
vector<pii> cities;
void init_pops() {
	for (int i = 1; i <= goal; i++)
		pops[i] = INF;
}

int main() {
	cin >> goal >> num;
	for (int i = 1; i <= num; i++) {
		cin >> cost >> increased_pop;
		cities.push_back({ cost, increased_pop });
		pops[increased_pop] = cost;
	}

	init_pops();
	for (int i = 1; i <= goal; i++) {
		for (int j = 0; j < cities.size(); j++) {
			for (int k = 1; k <= cities[j].second; k++) {
				if (i - k >= 0)
					pops[i] = min(pops[i], pops[i - k] + cities[j].first);
			}
		}
	}

	cout << pops[goal];
	return 0;
}
