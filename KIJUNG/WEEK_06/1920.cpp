#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M, tmp;
int A[100001];

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
        cout << binary_search(A, A+N, tmp) << "\n";
    }

    return 0;
}