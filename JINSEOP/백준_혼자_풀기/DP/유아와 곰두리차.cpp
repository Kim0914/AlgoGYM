#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define OPTIMIZE cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define mod 1000000007

int vertices = 0, edges = 0, from = 0, to = 0;
vector<int> graph[100001];
ll dp[8][100001];
int main() {
	OPTIMIZE;

	cin >> vertices >> edges;
	for (int i = 0; i < edges; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
		dp[0][from] = 1;
		dp[0][to] = 1; // 출발점으로의 가능성
	}

	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= vertices; j++) {
			for (int k = 0; k < graph[j].size(); k++) {
				dp[i][graph[j][k]] = ((dp[i][graph[j][k]] % mod) + ((dp[i - 1][j]) % mod)) % mod;
				// i 길이로 연결된 노드로 갈 수 있는 경로의 수는?
				// i - 1의 길이로 현재 노드까지 온 경로의 수를 더하면 된다.
			}
		}
	}

	ll result = 0;
	for (int i = 1; i <= vertices; i++)
		result = ((result % mod) + (dp[7][i] % mod)) % mod;
  // 결국, 길이 7의 경로로 도착할 수 있는 모든 정점의 경로 수를 더하면 됨
	cout << result;
	return 0;
}
