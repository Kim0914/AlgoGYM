#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
vector<int> edge[26];

void dfs(int cur, int flag){
    int left = edge[cur][0];
    int right = edge[cur][1];
    
    if(flag == 0) cout << (char)(cur+65);
    if(left != -1) dfs(left, flag);
    if(flag == 1) cout << (char)(cur+65);
    if(right != -1) dfs(right, flag);
    if(flag == 2) cout << (char)(cur+65);
}

int main(void){
    cin >> N;

    FOR(i,0,N){
        char t1,t2,t3;
        cin >> t1 >> t2 >> t3;
        if(t2 != '.') edge[t1-65].push_back(t2-65);
        else edge[t1-65].push_back(-1);
        if(t3 != '.') edge[t1-65].push_back(t3-65);
        else edge[t1-65].push_back(-1);
    }

    dfs(0,0);
    cout << "\n";
    dfs(0,1);
    cout << "\n";
    dfs(0,2);

    return 0;
}