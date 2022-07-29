#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
unordered_map<string, int> um;
bool compare(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}
bool compare2(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i = 0; i < genres.size(); i++){
        um[genres[i]] += plays[i];
    }
    vector<pair<string, int>> temp(um.begin(), um.end());
    sort(temp.begin(), temp.end(),compare);
    vector<vector<pair<int, int>>> song(temp.size());
    for(int i = 0; i < plays.size(); i++){
        for(int j = 0; j < temp.size(); j++){
            if(genres[i] == temp[j].first){
                song[j].push_back(make_pair(i, plays[i]));
            }
        }
    }
    for(int i = 0; i < song.size(); i++){
        sort(song[i].begin(), song[i].end(),compare2);
    }
    for(int i = 0; i < song.size(); i++){
        for(int j = 0; j < 2; j++){
            if(song[i].size() < 2 && j == 1) continue;
            answer.push_back(song[i][j].first);
        }
    }
    return answer;
}
