#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int truckSum = 0;
    int time = 0;
    queue<pair<int, int>> q;
    
    for(int i=0;i<truck_weights.size();i++){
        if(!q.empty() && time == q.front().first){
            truckSum -= q.front().second;
            q.pop();
        }
        
        if(truckSum + truck_weights[i] <= weight){
            truckSum += truck_weights[i];
            q.push(make_pair(time+bridge_length, truck_weights[i]));
            time++;
        }
        else{
            while(truckSum + truck_weights[i] > weight && !q.empty()){
                time = q.front().first; //max(q.front().first,time);
                truckSum -= q.front().second;
                q.pop();
            }
            i--;
        }
    }

    while(!q.empty()){
        time = q.front().first;
        q.pop();
    }

    return time+1;
}