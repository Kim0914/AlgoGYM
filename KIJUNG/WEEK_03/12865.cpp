#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int N, K;
int wei[101];
int val[101];
int dp[101][100001];

int main(void){
    cin >> N >> K;
    FOR(i,1,N+1){
        cin>> wei[i] >> val[i];
    }

    FOR(i,1,N+1){
        FOR(j,1,K+1){
            if(j>=wei[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-wei[i]] + val[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[N][K];

    return 0;
}

// 가치, 돈, 물건 이렇게 3개의 변수가 있을 때 어떤 변수를 인덱스화 할 것인가!!!! 순서는 어떻게 할 것인가!!!! << 큰 깨달음
// 이번 문제는 [물건][무게] = 값어치
 
// 왜 이렇게 처음부터 접근하지 못했나? 물건을 차례대로 인덱스 돌린다는 생각을 못했다. 왜냐하면 해당 값에서 물건이 있는지 없는지를 저장하려고 접근했기 때문..
// 있는 거 없는 거는 모르겠고 물건을 차례대로 그냥 물건을 넣고 안넣고를 고려해서 무게에서 값어치가 높은 거를 저장하면 됨.
// 들어있을 때 무게, 안 들어있을 때 무게를 저장해서 쓰려고 하면 안된다.
