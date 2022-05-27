#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, num1, num2;
bool visited[10000];
string op[10000];
string e[4] = {"D","S","L","R"};
int before[10000];

int main(void){
    // cout << -1%10000;
    cin >> T;
    while(T--){
        string ans = "\0";
        int result[4];
        queue<int> q;

        fill(visited,visited+10000,false);
        fill(op,op+10000,"\0");
        fill(before,before+10000,0);

        cin >> num1 >> num2;

        q.push(num1);

        while(!q.empty()){
            int cur = q.front();
            // cout << cur << " ";
            if(cur == num2)break;
            q.pop();
            result[0] = (2*cur)%10000;
            result[1] = (10000+cur-1)%10000;
            result[2] = ((cur*10)+(cur/1000))%10000;
            result[3] = ((cur%10)*1000+(cur/10))%10000;
            
            FOR(i,0,4){
                if(!visited[result[i]]){
                    q.push(result[i]);
                    visited[result[i]] = true;
                    before[result[i]] = cur;
                    op[result[i]] = e[i];
                }
            }
        }
        
        int track = num2;
        while(track!=num1){
            // cout << op[track] << " ";
            ans += op[track];
            track = before[track];
        }
        reverse(ans.begin(),ans.end());
        cout << ans << "\n";
    }

    return 0;
}