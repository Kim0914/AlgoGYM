#include <iostream>
#include <algorithm>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N, tmp;
priority_queue<int> q;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    FOR(i,1,N+1){
        cin >> tmp;
        if(tmp == 0){
            if(!q.empty()){
                cout << q.top() << "\n";
                q.pop();
            }
            else cout << 0 << "\n";
        }
        else if(tmp>0){
            q.push(tmp);
        }
    }

    return 0;
}