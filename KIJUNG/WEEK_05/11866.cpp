#include <iostream>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, K;
queue<int> q;
queue<int> p;

int main(void){
    cin >> N >> K;

    FOR(i,1,N+1){
        q.push(i);
    }

    int idx = 1;
    while(!q.empty()){
        
        if(idx%K == 0){
            p.push(q.front());
        }else q.push(q.front());
        q.pop();
        idx++;
    }

    cout << "<" << p.front();
    while(1){
        p.pop();
        if(p.empty()) break;
        cout << ", " <<p.front() ;
    }
    cout << ">";

    return 0;
}