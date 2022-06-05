#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

long long solution(int n, vector<int> times) {
    priority_queue<pair<long long,int>, vector<pair<long long,int> >, greater<pair<long long,int> > > pq;
    long long answer = 0;

    FOR(i,0,times.size()){
        pq.push(make_pair((long long)times[i], times[i]));
    }
    
    while(n--){
        answer = pq.top().first;
        pq.push(make_pair(pq.top().first+(long long)pq.top().second,pq.top().second));
        pq.pop();
    }
    
    return answer;
}

//시간초과.