#include <iostream>
#include <queue>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int N;
queue<int> q;

int main(void){
    cin >> N;
    FOR(i,1,N+1){
        q.push(i);
    }
    while(!q.empty()){
        if(q.size() == 1) cout <<q.front();
        q.pop();
        q.push(q.front());
        q.pop();
    }
    return 0;
}