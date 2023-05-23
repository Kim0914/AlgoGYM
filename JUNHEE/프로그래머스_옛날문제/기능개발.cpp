#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i = 0; i < progresses.size(); i++){
        int diff = 100 - progresses[i];
        int date = diff / speeds[i];
        if(diff % speeds[i] != 0)
            date++;
        q.push(date);
    }
    while(!q.empty()){
        int cnt = 1;
        int t_ans = q.front();
        q.pop();
        while(q.front() <= t_ans && !q.empty()){
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }
    return answer;
}
