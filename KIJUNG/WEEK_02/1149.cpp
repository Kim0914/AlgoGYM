#include <iostream>
#include <math.h>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int price[1001][3];
int N;

int main(void){
    cin >> N;

    FOR(i,1,N+1){
        cin >> price[i][0] >> price[i][1] >> price[i][2];
    }
    FOR(i,2,N+1){
        price[i][0] += min(price[i-1][1],price[i-1][2]);
        price[i][1] += min(price[i-1][0],price[i-1][2]);
        price[i][2] += min(price[i-1][1],price[i-1][0]);
    }
    cout << min(price[N][0], min(price[N][1], price[N][2]));

    return 0;
}