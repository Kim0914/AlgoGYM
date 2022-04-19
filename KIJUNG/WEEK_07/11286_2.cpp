#include <iostream>
#include <queue>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, tmp;
priority_queue<pair<int,int> > pq;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    FOR(i,0,N){
        cin >> tmp;
        
        if(tmp) pq.push(make_pair(-abs(tmp),-tmp));
        else if(pq.empty()) cout << "0\n";
        else {
            cout << -pq.top().second << "\n";
            pq.pop();
        }
    }
    return 0;
}

//pair를 이용한 풀이