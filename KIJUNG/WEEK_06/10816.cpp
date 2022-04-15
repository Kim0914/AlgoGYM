#include <iostream>
#include <algorithm>
#include <array>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M, tmp;
int A[500001];

array<int,500001> :: iterator upper, lower;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    FOR(i,0,N){
        cin >> A[i];
    }
    sort(A, A+N);

    cin >> M;
    FOR(i,0,M){
        cin >> tmp;
        upper = upper_bound(A,A+N,tmp);
        lower = lower_bound(A,A+N,tmp);
        cout << upper - lower << " ";
    }

    return 0;
}