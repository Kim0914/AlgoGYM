#include <iostream>
#include <algorithm>
#include <string>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

string str1, str2, lcs;
int dp[1001][1001];

int main(void){
    cin >> str1 >> str2;

    FOR(i,1,str1.size()+1){
        FOR(j,1,str2.size()+1){
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    int len = dp[str1.size()][str2.size()];
    cout << len << "\n";

    int y = str1.size();
    int x = str2.size();

    while(dp[y][x]){
        if(dp[y][x] == dp[y-1][x]) y--;
        else if(dp[y][x] == dp[y][x-1]) x--;
        else {
            lcs = str1[y-1] + lcs;
            y--;
            x--;
        }
    }
    if(lcs.size() > 0) cout << lcs;

    return 0;
}