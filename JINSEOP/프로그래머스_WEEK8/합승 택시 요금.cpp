#include <string>
#include <vector>
using namespace std;
#define INF 10000000

int dist[201][201];

void init_dist(int n) {
    // Floyd Warshall 초기화
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = INF;

    for (int i = 1; i <= n; i++) dist[i][i] = 0;
}

void make_graph(vector<vector<int>> fares) {
    for (auto fare : fares) {
        dist[fare[0]][fare[1]] = fare[2];
        dist[fare[1]][fare[0]] = fare[2];
    }
}

void floyd_warshall(int n) {
    for (int mid = 1; mid <= n; mid++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][mid] + dist[mid][j], dist[i][j]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    init_dist(n);
    make_graph(fares);
    floyd_warshall(n);

    for (int i = 1; i <= n; i++)
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
        // 이 말은 시작 ==> 특정 지점 + 특정 지점 ==> A + 특정 지점 ==> B 가 된다.
        // 그 중 비용이 최소가 되는 경로가 저장된다.
    
    return answer;
}
