#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define pii pair<int, int>

pii dp[100001];
bool validate(int next_score, int curr_score) {
    if (next_score < 0)
        return false; // 버스트

    if (dp[next_score].first && (dp[next_score].first <= dp[curr_score].first))
        return false;
    // 다음 점수에 이미 탐색한 기록이 있는데
    // 횟수가 현재 횟수와 같거나 더 적으면 탐색할 필요 X

    if ((dp[next_score].first == dp[curr_score].first + 1) && dp[next_score].second > dp[curr_score].second)
        return false;
    // 현재 점수에서 하나 더 던져서 다음 점수를 만들 수 있는 경우
    // 즉, 던진 횟수가 같은 tie break의 경우에
    // 볼 + 싱글의 경우가 현재 더 적으면 탐색할 필요 X

    return true;
}

vector<int> solution(int target) {
    vector<int> answer;

    for (int curr_score = target; curr_score > 0; curr_score--) {
        for (int next_score = 1; next_score <= 20; next_score++) {
            for (int coef = 1; coef <= 3; coef++) {
                int next = curr_score - (next_score * coef);

                if (!validate(next, curr_score))
                    continue;

                dp[next].first = dp[curr_score].first + 1;
                if (coef == 1) // 싱글을 맞추는 경우
                    dp[next].second = dp[curr_score].second + 1;
                else // 아닌 경우 현행 유지
                    dp[next].second = dp[curr_score].second;
            }
        }

        int next = curr_score - 50; // 불
        
        if (!validate(next, curr_score))
            continue;

        dp[next].first = dp[curr_score].first + 1;
        dp[next].second = dp[curr_score].second + 1;
        // 불은 무조건 올려주어야 함
    }

    answer.push_back(dp[0].first);
    answer.push_back(dp[0].second);
    return answer;
}

int main() {
    solution(58);
	return 0;
}
