#include <string>
#include <vector>
using namespace std;

int max_fat = 0;
void backtracK(int depth, int fatigue, int start, vector<vector<int>> dungeons, vector<bool>& visit) {
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visit[i] && fatigue >= dungeons[i][0]) {
            visit[i] = true;
            fatigue -= dungeons[i][1];
            backtracK(depth+1, fatigue, i, dungeons, visit);
            visit[i] = false;
            fatigue += dungeons[i][1];
        }
    }

    max_fat = max(max_fat, depth);
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> visit(dungeons.size(), 0);

    backtracK(0, k, 0, dungeons, visit);
    answer = max_fat;

    return answer;
}

// Backtrack
