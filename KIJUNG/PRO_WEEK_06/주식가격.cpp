#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<int> q[10001];

    for(int i=0;i<prices.size();i++){
        q[prices[i]].push(i);
    }

    for(int i=0;i<prices.size();i++){
        int cur = q[prices[i]].front();
        int m = prices.size()-1-i;
        for(int j=0;j<cur;j++){
            if(q[j].front()<m){
                m = q[i].front();
            }
        }
        answer.push_back(m-i);
        q[prices[i]].pop();
    }

    return answer;
}

// 시간초과 시간복잡도 n*m
// worst case가 10000*100000라서 10억이네..