#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define WRITEFOR(X, arr_len) for(int i = 0; i < arr_len; i++) cin >> X[i];
#define READFOR(X, arr_len) for(int i = 0; i < arr_len; i++) cout << X[i] << " ";

ll target_sum = 0, answer = 0;
int a_len = 0, b_len = 0;
ll A[1000], B[1000];
vector<int> partial_A, partial_B;
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    optimize();
    cin >> target_sum;

    cin >> a_len;
    WRITEFOR(A, a_len);
    cin >> b_len;
    WRITEFOR(B, b_len);

    for (int i = 0; i < a_len; i++) {
        int sum = A[i];
        partial_A.push_back(sum);
        for (int j = i + 1; j < a_len; j++) {
            sum += A[j];
            partial_A.push_back(sum);
        }
    }

    for (int i = 0; i < b_len; i++) {
        int sum = B[i];
        partial_B.push_back(sum);
        for (int j = i + 1; j < b_len; j++) {
            sum += B[j];
            partial_B.push_back(sum);
        }
    }
    // A와 B의 부분 합을 미리 계산 해놓는다.

    sort(partial_B.begin(), partial_B.end());
    // B의 부분 합이 저장된 배열을 정렬한다.

    for (int i = 0; i < partial_A.size(); i++) {
        int diff = target_sum - partial_A[i];
        // 목표하는 합 - A의 부분합 = B의 부분합이 되어야 한다고 식을 바꿀 수 있다.
        // 따라서, B의 부분 합 중에서 (목표 합 - A의 부분합)과 동일한 수를 세면 된다.

        // 이 때 그냥 B의 부분 합 배열을 돌면서 찾게 되면 시간 초과가 발생한다.
        auto ub = upper_bound(partial_B.begin(), partial_B.end(), diff);
        auto lb = lower_bound(partial_B.begin(), partial_B.end(), diff);
        // 그래서 이분 탐색으로 수를 찾는 x_bound 함수를 이용하도록 한다.
        // upper_bound는 B의 부분 합 중 diff를 초과하는 수가 처음으로 나오는 iterator를 반환한다.
        // lower_bound는 B의 부분 합 중 diff 이상의 수가 처음으로 나오는 iterator를 반환한다.

        answer += (ub - lb);
        // 해당 iterator 간의 거리를 빼게 되면 무조건 1이 된다.
        // lower_bound는 diff와 동일한 수를 찾을 것이고, upper_bound는 항상 그것보다 하나 큰 인덱스를 잡을 것이기 때문!
    }

    cout << answer;
    return 0;
}
