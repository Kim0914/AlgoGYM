#include <iostream>
#include <string>
using namespace std;

int tc = 0;
string src1 = "", src2 = "", target = "";
int main() {
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> src1 >> src2 >> target;

        int src1_ptr = 0, src2_ptr = 0;
        for (int target_ptr = 0; target_ptr < target.size(); target_ptr++) {
            if (target[target_ptr] == src1[src1_ptr] && target[target_ptr] == src2[src2_ptr]) {
                // 동시에 맞는 알파벳이 있으면?
                if (src1_ptr > src2_ptr)
                    src2_ptr++;
                else
                    src1_ptr++;
                // 진행률이 더 낮은 포인터를 뒤로 미뤄보자

                continue; // 다음 과정으로
            }

            if (target[target_ptr] == src1[src1_ptr])
                src1_ptr++;
            else if (target[target_ptr] == src2[src2_ptr])
                src2_ptr++;
        }

        if(src1_ptr == src1.size() && src2_ptr == src2.size())
            cout << "Data set " << (i + 1) << ": yes";
        else
            cout << "Data set " << (i + 1) << ": no";
    }

    return 0;
}

// 여기 아래가 맞는 풀이
#include <iostream>
#include <string>
using namespace std;

int tc = 0;
string src1 = "", src2 = "", target = "";
int dp[201][201];
void clear_dp() {
    for (int i = 0; i <= src1.size(); i++)
        for (int j = 0; j <= src2.size(); j++)
            dp[i][j] = 0;
}

int main() {
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> src1 >> src2 >> target;

        dp[0][0] = 1;
        // DP 배열에서 src1이 행 src2가 열 담당.

        for (int i = 1; i <= src2.size(); i++)
            if (src2[i-1] == target[i-1] && dp[0][i-1])
                dp[0][i] = 1;
        // 현재 글자도 같고, 앞글자도 같으면 1.
        // 여기까지는 만들 수 있다는 의미 (src2)
        for (int i = 1; i <= src1.size(); i++)
            if (src1[i-1] == target[i-1] && dp[i-1][0])
                dp[i][0] = 1;
        // 현재 글자도 같고 앞글자도 같으면 1.
        // 여기까지는 만들 수 있다는 의미 (src1)
        for (int i = 1; i <= src1.size(); i++) {
            for (int j = 1; j <= src2.size(); j++) {
        // 여기부터 안쪽 글자들을 비교해 나간다.
        // src1 기준으로 이전 글자와 현재 target의 글자가 같으면 1
        // src2 기준으로도 확인을 해야 한다.
        // target의 인덱스가 i + j - 1인 이유는?
        // target을 검사하며 src1와 같으면 i++, src2가 같으면 j++이 되기 때문!
        // 즉, 현재 검사하고 있는 칸은 i + j번째 칸이 된다.
                if ((dp[i - 1][j] && (src1[i - 1] == target[i + j - 1])) || (dp[i][j - 1] && (src2[j - 1] == target[i + j - 1])))
                    dp[i][j] = 1;
            }
        }

        if (dp[src1.size()][src2.size()])
            cout << "Data set " << i + 1 << ": yes\n";
        else
            cout << "Data set " << i + 1 << ": no\n";

        clear_dp();
    }

    return 0;
}
