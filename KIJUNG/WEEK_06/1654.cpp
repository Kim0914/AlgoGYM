#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, K;
long long ans;
int nums[10000];

bool passible(long long n){
    int tmp = 0;
    FOR(i,0,N){
        tmp += nums[i]/n;
        if(tmp>=K){
            ans = max(n, ans);
            return true;
        }
    }
    return false;
}

void solve(long long start, long long end){
    if(start > end) return;
    
    long long mid = (start+end)/2;
    if(passible(mid)) solve(mid+1,end);
    else solve(start,mid-1);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    FOR(i,0,N){
        cin >> nums[i];
    }

    for(long long k =1;;k*=2){
        if(!passible(k)) break;
    }

    solve(ans,ans*2);
    cout << ans << "\n";

    return 0;
}

//이분탐색으로 재귀를 돌 때는 long long 타입을 써서 오버플로우를 방지해야한다.