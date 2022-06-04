#include <string>
#include <vector>
#include <unordered_set>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int Ns(int N, int k){
    int result = N;
    FOR(i,1,k) result = result*10 + N;
    return result;
}

int solution(int N, int number) {
    vector<unordered_set<int> > dp(9);

    FOR(i,1,9){
        dp[i].insert(Ns(N,i));

        FOR(j,1,i){
            for(int k: dp[j]){
                for(int l: dp[i-j]){
                    dp[i].insert(k+l);
                    dp[i].insert(k*l);
                    if(k-l>0) dp[i].insert(k-l);
                    if(k/l>0) dp[i].insert(k/l);
                }
            }
        }

        if(dp[i].find(number)!=dp[i].end()) {
            return i;
        }
    }

    return -1;
}

// 풀이 방법 : 다이나믹 프로그래밍
// 점화식 
// -> N을 4개 써서 만들 수 있는 수일 때 점화식은 dp[1]*dp[3], dp[2]*dp[2], dp[3]*dp[1]로 만들 수 있는 수이다.