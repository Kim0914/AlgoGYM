#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int out = routes[0][1];
    
    for(auto i : routes){
        if(out < i[0]){
            answer++;
            out = i[1];
            cout << i[1];
        }
        if(out >= i[1]){
            out = i[1];
        }
    }
    return answer;
}
