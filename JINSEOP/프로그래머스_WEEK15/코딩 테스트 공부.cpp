#include <string>
#include <vector>
using namespace std;
#define INF 1000000000

int DP[151][151];
int max_alp = 0, max_cop = 0;
int study(int alp, int cop, vector<vector<int>>& problems) {
    if (alp >= max_alp && cop >= max_cop) return 0;

    if (alp > max_alp) alp = max_alp;
    if (cop > max_cop) cop = max_cop;

    int& res = DP[alp][cop];
    if (res != 0) return res;
    res = INF;

    for (auto vec : problems) {
        if (alp < vec[0] || cop < vec[1]) continue;
        res = min(res, study(alp + vec[2], cop + vec[3], problems) + vec[4]);
    }

    res = min(res, study(alp + 1, cop, problems) + 1);
    res = min(res, study(alp, cop + 1, problems) + 1);

    return res;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    for (auto vec : problems) {
        max_alp = max(max_alp, vec[0]);
        max_cop = max(max_cop, vec[1]);
    }
    
    answer = study(alp, cop, problems);
    return answer;
}

// 재귀와 DP에 대해서 좀 더 생각해볼 것!
