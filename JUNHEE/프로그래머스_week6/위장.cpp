#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> map;
    int answer = 1;
    for(int i = 0; i < clothes.size();i++){
        map[clothes[i][1]]++;
    }
    for(auto cl : map){
        answer *= (cl.second + 1);
    }
    return answer - 1;
}
