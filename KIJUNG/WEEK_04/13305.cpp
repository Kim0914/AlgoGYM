#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
long dis[100001];
long city[100001];
long cur;
long long cost = 0;

int main(void){
    cin >> N;
    FOR(i,1,N){
        cin >> dis[i];
    }
    FOR(i,1,N+1){
        cin >> city[i];
    }
    cur = city[1];
    FOR(i,1,N){}    
        cost += cur*dis[i];
        if(cur>city[i+1]){
            cur = city[i+1];
        }
    }

    cout <<cost;




    return 0;
}