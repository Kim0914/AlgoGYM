#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool compare(pair<float, int> a, pair<float, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> stage(N + 1, 0);
    vector<int> fail(N + 1, 0);
    vector<pair<float, int>> fail_rate(N);
    for(int i = 0; i < stages.size(); i++){
        fail[stages[i] - 1]++;
        for(int j = 0; j < stages[i]; j++){
            stage[j]++;
        }
    }
    for(auto i : fail){
        cout << i << " ";
    }cout << endl;
    for(auto i : stage){
        cout << i << " ";
    }
    for(int i = 0; i < N; i++){
        if(stage[i] == 0){ //스테이지에 도달한 사람이 없는 경우를 생각하지 못해서 헤맸다..
            fail_rate[i].first = 0.0;
            fail_rate[i].second = i + 1;
            continue;
        }
        fail_rate[i].first = (float)fail[i] / (float)stage[i];
        fail_rate[i].second = i + 1;
    }
    sort(fail_rate.begin(),fail_rate.end(), compare);
    
    for(auto i : fail_rate){
        answer.push_back(i.second);
    }
    return answer;
}
