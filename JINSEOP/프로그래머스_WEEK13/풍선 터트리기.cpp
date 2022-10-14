#include <string>
#include <vector>
using namespace std;

int left_DP[1000001];
int right_DP[1000001];
void init_DP(vector<int> a) {
    left_DP[0] = a[0];
    right_DP[a.size() - 1] = a[a.size() - 1];
}

void calculate_min_value(vector<int> a) {
    for (int i = 1; i < a.size(); i++)
        left_DP[i] = min(left_DP[i - 1], a[i]);

    for (int i = a.size() - 2; i > 0; i--)
        right_DP[i] = min(right_DP[i + 1], a[i]);
}

int find_answer(vector<int> a) {
    int cnt = 0;

    for (int i = 0; i < a.size(); i++) {
        if (i == 0 || i == a.size() - 1) {
            cnt++;
            continue;
        }

        if (a[i] < left_DP[i - 1] || a[i] < right_DP[i + 1])
            cnt++;
    }
    
    return cnt;
}

int solution(vector<int> a) {
    int answer = 0;

    init_DP(a);
    calculate_min_value(a);
    answer = find_answer(a);

    return answer;
}
