#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cur = 0;

    for(int i=1;i<100;i++){
        int cnt = 0;
        while(progresses[cur] + speeds[cur]*i >= 100 && cur<progresses.size()){
            cnt++;
            cur++;
        }
        if(cnt!=0) answer.push_back(cnt);
    }

    return answer;
}