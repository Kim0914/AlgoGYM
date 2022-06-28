#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int answerInt = 0;
    int lastTime = 0;
    queue<int> q;

    sort(timetable.begin(), timetable.end());
    for(string t: timetable) {
        int i = stoi(t.substr(0,2))*60 + stoi(t.substr(3,2));
        q.push(i);
    }

    for(int i=0;i<n;i++){
        int cnt = 0;
        while(!q.empty()){
            if(q.front() <= 540+t*i){
                lastTime = q.front();
                q.pop();
                cnt++;
                if(cnt == m) break;
            }
            else break;
        }
        if(i == n-1){
            if(cnt<m) answerInt = 540+t*i;
            else answerInt = lastTime-1;
        }
    }
    
    if(answerInt/60 < 10) answer += "0";
    answer += to_string(answerInt/60) + ":";
    if(answerInt%60 < 10) answer += "0";
    answer += to_string(answerInt%60);

    return answer;
}