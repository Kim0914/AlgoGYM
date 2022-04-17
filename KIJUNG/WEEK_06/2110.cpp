#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, C;
int h[200000];
long long ans;

bool passible(long long n){
    long long cnt = 1;
    int tmp = h[0];
    FOR(i,1,N){
        if((h[i] - tmp)>=n) {
            tmp = h[i];
            cnt++;
            if(cnt >= C) {
                if(n > ans) ans = n;
                return true;
            }
        }
    }
    return false;
}

void solve(long long start, long long end){
    if(start > end) return;
    long long mid = (start + end)/2;
    if(passible(mid)) solve(mid+1,end);
    else solve(start, mid-1);
}

int main(void){
    cin >> N >> C;
    FOR(i,0,N){
        cin >> h[i];
    }
    sort(h,h+N);

    for(int i=1;;i*=2){
        if(!passible(i)) break;
    }

    solve(ans, ans*2);
    cout << ans;

    return 0;
}