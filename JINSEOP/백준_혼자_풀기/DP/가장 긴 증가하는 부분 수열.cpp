#include <iostream>
#include <vector>
using namespace std;

int num = 0, answer = 0;
int seq[1000];
int dp[1000];
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    optimize();
    
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> seq[i];
    }

    for (int i = 0; i < num; i++) {
        dp[i] = 1;
        
        for (int j = i - 1; j >= 0; j--)
            if (seq[i] > seq[j])
                dp[i] = max(dp[i], dp[j] + 1);

        answer = max(dp[i], answer);
    }

    cout << answer;
    return 0;
}
