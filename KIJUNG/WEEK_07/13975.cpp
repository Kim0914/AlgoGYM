#include <iostream>
#include <algorithm>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, K, tmp;
long long low1, low2;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    FOR(i,0,T){
        cin >> K;
        priority_queue<long long> pq;
        long long ans = 0;

        FOR(j,1,K+1){
            cin >> tmp;
            pq.push(-tmp);
        }
        
        while(pq.size() > 1){
            low1 = pq.top();
            pq.pop();
            low2 = pq.top();
            pq.pop();
            pq.push(low1+low2);
            ans += low1+low2;
        }
    
        cout << -ans << '\n';
    }
    return 0;
}