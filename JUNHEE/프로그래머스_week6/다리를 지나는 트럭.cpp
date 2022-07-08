#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int b_w = 0, index = 0, time = 1;
    queue<int> q;
    queue<int> s_time;
    q.push(truck_weights[index]);
    b_w += truck_weights[index];
    s_time.push(time);
    time++; index++;
    int temp_time, temp_weight;
    while(!q.empty()){
        temp_time = s_time.front();
        if(temp_time + bridge_length == time){
            temp_weight = q.front();
            q.pop();
            s_time.pop();
            b_w -= temp_weight;
        }
        if(b_w + truck_weights[index] <= weight){
            if(index < truck_weights.size()){
                cout << "Im in : " << truck_weights[index] << " in " << time << endl;
                q.push(truck_weights[index]);
                b_w += truck_weights[index];
                s_time.push(time);
                index++;
            }
        }
        time++;
    }
    cout << time - 1;
    return time - 1;
}
