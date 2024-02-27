#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

vector<int> permutation;
int result = INF;
bool visit[8];
void circulate_weak(int n, vector<int> &weak) {
    int size = weak.size();
    for (int i = 0; i < size - 1; i++)
        weak.push_back(weak[i] + n);
    // 취약 지점을 원형으로 만들기 위해 뒤에 값을 추가한다.
    // 마지막 지점을 제외한 나머지 지점 추가
}

void backtrack(int depth, int idx, int limit, vector<int> dist, vector<int> weak) {
    if (depth == dist.size()) {
        for (int i = 0; i < limit; i++) {
            int from = weak[i]; // 출발 지점
            int end = weak[i + limit - 1];
            // 종료 지점은 출발지에 대해 정반대편

            for (int j = 0; j < permutation.size(); j++) {
                from += permutation[j]; // 시작 지점부터 탐색 가능 거리 더하기

                if (from >= end) {
                // 시작지점 >= 끝지점이 되면 순찰을 완료한 것
                    result = min(result, j + 1);
                    break;
                }

                
                for (int k = i + 1; k < i + limit; k++) {
                    if (weak[k] > from) {
                        from = weak[k];
                        break;
                    }
                } // 외벽 점검이 끝나지 않았지만, 이동할 수 없는 경우
                // 다음 취약 지점으로 이동해서 친구를 움직여야 한다.
            }
        }

        return;
    }

    for (int i = 0; i < dist.size(); i++) {
        if (!visit[i]) {
            visit[i] = true;
            permutation.push_back(dist[i]);
            backtrack(depth + 1, i, limit, dist, weak);
            visit[i] = false;
            permutation.pop_back();
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;

    sort(dist.begin(), dist.end(), greater<>());
    // 친구들 이동거리 내림차순 정렬
    int origin_weak_size = weak.size();
    circulate_weak(n, weak);

    for (int i = 0; i < dist.size(); i++) {
        visit[i] = true;
        permutation.push_back(dist[i]);
        backtrack(1, i, origin_weak_size, dist, weak);
        visit[i] = false;
        permutation.pop_back();
    }

    if (result == INF)
        return -1;
    else
        answer = result;
    return answer;
}

int main() {
    solution(12, {1,5,6,10}, {1,2,3,4});
	return 0;
}
