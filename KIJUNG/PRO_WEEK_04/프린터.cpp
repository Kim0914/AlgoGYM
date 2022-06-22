#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int cnt=1;
    int priorCheck[10] = {0,};
    deque<pair<int,int> > q;
    
    for(int i=0;i<priorities.size();i++){
        q.push_back(make_pair(priorities[i],i));
        priorCheck[priorities[i]]++;
    }
    
    for(int i=9;i>0;i--){
        if(priorCheck[i] == 0) continue;
        for(int j=0;j<q.size(), priorCheck[i] > 0;j++){
            if(q.front().first != i) q.push_back(q.front());
            else {
                if(location == q.front().second) return cnt;
                priorCheck[i]--;
                cnt++;
            }
            q.pop_front();
        }
    }
    
    return 0;
}