#include <iostream>
#include <string>

#define FOR(i,a,b) for(int i =a;i<b;i++)

using namespace std;

string str1;
string str2;
int dp[1000];
int cnt = 0;

int main(void){
    cin >> str1 >> str2;

    fill(dp,dp+1000,1);

    FOR(i,0,str1.size()){
        
    }
    cout <<"\n"<< cnt;

    return 0;

}
//LCS알고리즘 공부하고 다시 풀어보기