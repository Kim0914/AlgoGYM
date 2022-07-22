#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.rbegin(), people.rend());
    int idx = 0;
    while(idx < people.size()){
        int small = people.back();
        if(people[idx] + small <= limit){
            answer++;
            idx++;
            people.pop_back();
        }else{
            answer++;
            idx++;
        }
    }
    return answer;
}
