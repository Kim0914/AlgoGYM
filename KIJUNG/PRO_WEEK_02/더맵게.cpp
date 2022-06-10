#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    
    int answer = 0;
    priority_queue<long, vector<long>, greater<long> > pq;

    for(int food: scoville){
        pq.push((long)food);
    }

    while(true){
        int first = pq.top();
        pq.pop();

        if(first>(long)K) break;

        if(pq.empty()) return -1;

        int second = pq.top();
        pq.pop();

        pq.push(first+second*2);
        answer++;
    }
    return answer;
}