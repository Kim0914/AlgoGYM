#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M;
long long ans = 0;
int tree[1000000];

bool passible(long long n){
    long long tmp = 0;
    FOR(i,0,N){
        if(tree[i]>n) tmp += tree[i]-n;
    }
    if(tmp>=M){
        if(n>ans) ans = n;
        return true;
    } 
    return false;
}

void solve(long long start, long long end){
    if(start > end) return;
    long long mid = (start + end)/2;
    if(passible(mid)) solve(mid+1, end);
    else solve(start, mid-1);
}

int main(void){
    cin >> N >> M;

    FOR(i,0,N){
        cin >> tree[i];
    }

    for(long long i = 1;;i*=2){
        if(!passible(i)) break;
    }    

    solve(ans,ans*2);
    cout << ans;

    return 0;
}