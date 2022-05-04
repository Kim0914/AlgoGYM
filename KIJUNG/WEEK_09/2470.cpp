#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, ansL, ansR;
vector<int> sol;
int m = 2000000000;

int main(void){
    cin >> N;
    int tmp;

    FOR(i,0,N){
        cin >> tmp;
        sol.push_back(tmp);
    }

    sort(sol.begin(), sol.end());

    int left = 0;
    int right = N-1;

    while(left<right){
        int cur = sol[left] + sol[right];
        if(abs(cur)<m){
            ansL = left;
            ansR = right;
            m = abs(cur);
        }
        if(cur > 0) right--;
        else if(cur < 0) left++;
        else break;
    }
    cout << sol[ansL] << " " << sol[ansR];

    return 0;
}