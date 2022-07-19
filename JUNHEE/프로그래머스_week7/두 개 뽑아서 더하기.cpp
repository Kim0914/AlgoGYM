#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<int> list;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i = 0; i < numbers.size(); i++){
        for(int j = i + 1; j < numbers.size(); j++){
            list.insert(numbers[i] + numbers[j]);
        }
    }
    for(auto i : list){
        answer.push_back(i);
    }
    return answer;
}
