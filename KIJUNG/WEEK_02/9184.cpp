#include <iostream>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int x, y, z;

int dp[102][102][102];

int w(int a, int b, int c){
    
    if(dp[a+50][b+50][c+50] != 0) return dp[a+50][b+50][c+50];

    if(a<=0 || b<=0 || c<=0) return dp[a+50][b+50][c+50] = 1;
    else if(a>20 || b>20 || c>20) return dp[a+50][b+50][c+50] = w(20,20,20);
    else if(a<b && b<c) return dp[a+50][b+50][c+50] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c) ;
    else return dp[a+50][b+50][c+50] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);

}

int main(void){
    FOR(i,-50,51) FOR(j,-50,51) FOR(k,-50,51){
        // cout << i <<" " << j <<" "<< k<<"\n";
        w(i,j,k);
    }

    while(1){
        cin >> x >> y >> z;
        if(x == -1&& y == -1 && z == -1) exit(0);
        cout << "w(" << x <<", "<<y<<", "<<z<<") = "<<dp[x+50][y+50][z+50]<<"\n";
    }

    return 0;
}