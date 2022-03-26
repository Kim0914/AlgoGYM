#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#define FOR(i,a,b) for(int i =a;i<b;i++)

using namespace std;

string str1, str2;
int dp[1001][1001];
int cnt = 0;

int main(void){
    cin >> str1 >> str2;

    FOR(i,1,str1.size()+1){
        FOR(j,1,str2.size()+1){
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[str1.size()][str2.size()];

    return 0;

}
// LCS알고리즘(Longest Common Subsequence, 최장 공통 부분 수열)
// 두 문자열에서 순서를 고려할 때 연속성을 배제한 공통문자들의 최대길이를 찾는 것이 관건이다!

// 이 알고리즘은 전형적인 dp문제를 2차원으로 옮겨 놓은거 뿐이다.
// 그래서 일반적으로 연속성을 최대문자열 길이를 찾는 문제보다 어려웠다.

// 반복문의 인덱스 dp값에서 좌우, 위아래, 대각선 값의 관계를 파악하는 게 중요하다.

// 문제를 예를 들어 설명하면
// 문자가 같은 경우, 각 인덱스에서 -1한 왼쪽 대각선의 dp값에 +1을 해준다. 
// 이 말의 의미는 해당 인덱스에서 값이 같으니 두 문자열의 해당 인덱스를 접근하기전 최대 값에서 +1을 한다는 의미다.
// 다를 경우, (i-1, j) / (i, j-1) 에서 큰 값을 가져오면 된다.
// 두 i, j에 해당하는 문자열에서 길이가 하나 적은 문자열 중 최대값을 취하겠다는 의미다. 
// 어차피 같지 않으니 길이가 1씩 적은 두 문자열에서 최대값을 가져오면 될 일이다!

// 이 문제에서 str1[i] == str2[j] 이렇게 직관적으로 조건문을 걸고 싶었으나 이렇게 할 경우 인덱스 값을 조정하는 과정에서
// 에러가 발생하기도하고 생각할 부분이 많아지기에 대각선인 i-1, j-1을 비교하는 형식을 취했다.

// 일차원문제는 백준 실버에서 풀어봤으니, 이차원 dp를 잘 푸는 연습을 해야겠다!