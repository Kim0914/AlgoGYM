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

//////////////////////////// 아래는 분기가 많아진 DP(튜닝)

#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define pii pair<int, int>

pii dp[100001];
void fill_dp(int target) {
    if (dp[target - 60].first == dp[target - 50].first) {
        dp[target].first = dp[target - 50].first + 1;
        dp[target].second = max(dp[target - 60].second, dp[target - 50].second + 1);
        // 트리플을 하거나, 불을 던져 불 + 1을 하거나
    }
    else if (dp[target - 60].first < dp[target - 50].first) {
        dp[target].first = dp[target - 60].first + 1;
        dp[target].second = dp[target - 60].second;
    }
    else {
        dp[target].first = dp[target - 50].first + 1;
        dp[target].second = dp[target - 50].second + 1;
    }
}

vector<int> solution(int target) {
    vector<int> answer;

    for (int i = 1; i <= target; i++) {
        // 1. 싱글 1회, 불 1회로 끝나는 경우
        if (i == 50 || i <= 20) {
            dp[i].first = 1;
            dp[i].second = 1;
        }
        // 2. 60이하일 때, 3의 배수인 경우
        else if (i <= 60 && i % 3 == 0) {
            dp[i].first = 1;
            dp[i].second = 0;
        }
        // 3. 40이하일 때, 2의 배수인 경우
        else if (i <= 40 && i % 2 == 0) {
            dp[i].first = 1;
            dp[i].second = 0;
        }
        // 4. 51 ~ 70일 때 불 + 싱글
        else if (i > 50 && i <= 70) {
            dp[i].first = 2;
            dp[i].second = 2;
        }
        // 위의 경우에 포함되지 않는 경우
        else if (i < 70) {
            // 40보다 작은 경우는 싱글 + 싱글
            if (i < 40) {
                dp[i].first = 2;
                dp[i].second = 2;
            }
            // 아니라면 싱글 + 더블 혹은 싱글 + 트리플
            else {
                dp[i].first = 2;
                dp[i].second = 1;
            }
        }
        // 남은 경우는 모두 dp로 해결
        else
            fill_dp(i);
    }

    answer.push_back(dp[target].first);
    answer.push_back(dp[target].second);
    return answer;
}

int main() {
    solution(58);
	return 0;
}
