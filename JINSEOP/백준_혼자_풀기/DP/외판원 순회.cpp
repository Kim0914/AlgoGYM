#include <iostream>
#include <cstring>
using namespace std;
#define INF 999999999

int num = 0, graph[16][16];
int dp[16][1 << 16];
int dfs(int curr, int visit) {
    if (visit == (1 << num) - 1) {
    // 모든 도시를 다 방문했다면?
        if (graph[curr][0] == 0)
            return INF;
        // 출발지를 의미하는데, 출발지가 0이라면 갈 수 없는 곳이다.
        // INF를 반환
        return graph[curr][0];
        // 출발지가 갈 수 있는 위치라면, 출발 지점까지의 비용 반환
    }

    if (dp[curr][visit] != -1)
        return dp[curr][visit];
    // -1로 처음에 초기화를 했었다.
    // -1이 아니라는 것은, 이미 탐색한 상태라는 것!
    // 해당 상태에서의 최소 비용을 반환한다.

    dp[curr][visit] = INF;
    // -1이라는 것은, 아직 탐색하지 않은 지점이라는 것
    // 비용 갱신을 위해 INF로 갱신한다.

    for (int i = 0; i < num; i++) {
        if (graph[curr][i] != 0 && ((visit & (1 << i)) != (1 << i)))
        // 탐색을 진행하는 경우는, 해당 도시로 가는 길이 있어야 한다.
        // 또한 방문하지 않은 도시여야 하기 때문에 우측과 같은 비트 연산을 진행한다.
        // visit & (1 << i)를 했을 때, 방문하지 않은 도시라면 0으로 바뀌게 된다.
        // 따라서 1 << i와 형태가 반드시 달라질 것!
            dp[curr][visit] = min(dp[curr][visit], graph[curr][i] + dfs(i, visit | 1 << i));
        // 배열에는 방문한 도시 상태에 대하여, 현재 도시까지의 거리를 갱신한다.
        // 재귀를 통해 도시를 모두 방문할 수 있도록 한다.
        // i와 visit | 1 << i를 넘긴다는 말은, 다음 도시와 그 도시를 방문한 상태를 넘기는 것이다.
    }

    return dp[curr][visit];
    // 모든 도시를 탐색한 뒤, 현재 상태에서의 비용을 반환한다.
}

int main(){
    cin >> num;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            cin >> graph[i][j];

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1);

    return 0;
}
