#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, idx = 0;
    sort(people.begin(),people.end());
    while(idx<people.size()){
        if(people.back()+people[idx]<=limit){
            idx++;
        }
        people.pop_back();
        answer++;
    }
    return answer;
}