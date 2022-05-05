#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

long long N, C, cnt, thing[31];
vector<long long> l, r;

void dfs(int start, int end, long long sum, vector<long long> &v){
    if(sum > C) return;
    if(start == end){
        if(sum != 0) v.push_back(sum);
        return;
    }
    dfs(start+1, end, sum, v);
    dfs(start+1, end, sum + thing[start], v);
}

int main(void){
    cin >> N >> C;

    FOR(i,0,N){
        cin >> thing[i];
    }

    dfs(0,N/2,0,l);
    dfs(N/2,N,0,r);

    sort(r.begin(), r.end());

    FOR(i,0,l.size()){
        long long possible = C - l[i];
        long long possibleCnt = upper_bound(r.begin(), r.end(), possible) - r.begin();
        cnt += possibleCnt;
    }

    cnt += l.size() + r.size() + 1;

    cout << cnt;

    return 0;
}

// Meet In The Middle 문제
// n이 클 때 사용
// 반으로 나눠서 각각 나눠진 덩어리에 대한 포인터를 둬야한다!
// 이전에 투포인트 풀었던 것 처럼 문제 조건에 맞춰서 포인터를 사용하여 문제를 해결하자!!!!