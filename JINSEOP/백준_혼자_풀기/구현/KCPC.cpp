#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tc = 0, team_num = 0, prob_num = 0, my_team = 0, log_num = 0;
int team_id = 0, prob = 0, score = 0;
int scores[101][101], submit_count[101], final_scores[101], turn[101];
bool cmp(int a, int b) {
    if (final_scores[a] == final_scores[b]) {
        if (submit_count[a] == submit_count[b])
            return turn[a] < turn[b];

        return submit_count[a] < submit_count[b];
    }

    return final_scores[a] > final_scores[b];
}

void clear_arrs() {
    for (int i = 1; i <= team_num; i++) {
        final_scores[i] = 0;
        submit_count[i] = 0;
        turn[i] = 0;

        for (int j = 1; j <= prob_num; j++)
            scores[i][j] = 0;
    }
}

int main() {
    cin >> tc;
    while (tc--) {
        vector<int> teams;
        cin >> team_num >> prob_num >> my_team >> log_num;

        for (int i = 0; i < log_num; i++) {
            cin >> team_id >> prob >> score;
            scores[team_id][prob] = max(scores[team_id][prob], score);
            // 여기까지 점수가 저장됨
            submit_count[team_id]++;
            turn[team_id] = i + 1;
        }

        for (int i = 1; i <= team_num; i++) {
            teams.push_back(i);
            for (int j = 1; j <= prob_num; j++)
                final_scores[i] += scores[i][j];
        } // 최종 점수 저장

        sort(teams.begin(), teams.end(), cmp);
        for (int i = 0; i < teams.size(); i++) {
            if (teams[i] == my_team) {
                cout << i + 1 << '\n';
                break;
            }
        }

        clear_arrs();
    }

    return 0;
}
