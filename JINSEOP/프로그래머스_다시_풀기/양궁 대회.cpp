#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> score_vec(11, 0);
vector<int> result(11, 0);
int max_diff = 0, max_last_idx = 0;
bool is_possible = false;
void backtrack(int curr_idx, int arrows, int apeach_score, int ryan_score, vector<int> &info) {
    if (arrows == 0) {
        if (ryan_score > apeach_score) {
            is_possible = true;
            int diff = ryan_score - apeach_score;

            if (max_diff <= diff) {
                if (max_diff == diff) {
                    if (curr_idx >= max_last_idx) {
                        if (max_last_idx == curr_idx) {
                            if (result[curr_idx] < score_vec[curr_idx])
                                result = score_vec;

                            return;
                        }

                        max_last_idx = curr_idx;
                        result = score_vec;
                    }

                    return;
                }

                max_last_idx = curr_idx;
                max_diff = diff;
                result = score_vec;
            }
        }

        return;
    }

    for (int i = curr_idx + 1; i < info.size(); i++) {
        if (arrows - (info[i] + 1) < 0)
            score_vec[i] += arrows;
        else
            score_vec[i] = info[i] + 1;

        int apeach_coef = 0, ryan_coef = 1;
        if (info[i] < score_vec[i]) {
            // 라이언이 이기면 계수를 1로 만들어야 함
            apeach_coef = 1;

            if (info[i] == 0) // 근데 어피치가 안쏜거면 0으로 다시 만듬
                apeach_coef = 0;
        }
        else // 어피치가 이기면 라이언 계수가 0이 됨
            ryan_coef = 0;

        backtrack(i, arrows - score_vec[i], apeach_score - ((10 - i) * apeach_coef), ryan_score + ((10 - i) * ryan_coef), info);
        score_vec[i] = 0;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    // 생각해보면, 1개만 많이 쏘면 해당 점수를 얻는다.
    // 따라서, 더 많은 화살을 굳이 쏠 필요가 없다.
    int apeach_score = 0;
    for (int i = 0; i < info.size(); i++)
        if (info[i] != 0)
            apeach_score += (10 - i);

    backtrack(-1, n, apeach_score, 0, info);
    
    if (is_possible)
        answer = result;
    else
        answer = { -1 };

    return answer;
}
