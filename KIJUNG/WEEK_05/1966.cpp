#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M, idx, tmp;

int main(void){
    cin >> N;

    FOR(i,0,N){
        int cnt = 0;
        queue<int> q;
        queue<int> s;
        vector<int> v;
        
        cin >> M >> idx;
        FOR(j,0,M){
            cin >> tmp;
            v.push_back(tmp);
            q.push(tmp);
            s.push(j);
        }
        sort(v.rbegin(), v.rend());
        
        while(!q.empty()){
            if(q.front() == v[cnt]){
                cnt++;
                if(idx == s.front())break;
                q.pop();
                s.pop();
            }else{
                q.push(q.front());
                s.push(s.front());
                q.pop();
                s.pop();
            }
        }
        cout << cnt << "\n";

    }

    return 0;
}