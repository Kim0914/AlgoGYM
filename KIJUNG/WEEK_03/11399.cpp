#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
int t[1001];
int sum = 0;

int main(void){
    cin >> N;
    FOR(i,1,N+1){
        cin >> t[i];
    }

    sort(t+1, t+N+1);

    FOR(i,1,N+1){
        sum += t[i]*(N+1-i);
    }
    cout << sum;
    return 0;
}