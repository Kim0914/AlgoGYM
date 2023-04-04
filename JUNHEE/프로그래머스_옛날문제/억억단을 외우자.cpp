#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> measure(e + 1, 1);
    vector<pair<int, int>> list;
    vector<int> answer;
    list.push_back(make_pair(1,1));
    for(int i = 2; i <= e; i++){
        for(int j = i; j <= e; j += i){
            measure[j]++;
        }
        list.push_back(make_pair(i, measure[i]));
    }
    sort(list.begin(), list.end(), cmp);
    for(int i = 0; i < starts.size(); i++){
        for(int j = 0; j < list.size(); j++){
            if(starts[i] <= list[j].first){
                answer.push_back(list[j].first);
                break;
            }
        }
    }
    return answer;
}
