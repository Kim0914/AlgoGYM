#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b){
    return a > b;
}
int calc(vector<int> citations, int num){
    int count = 0;
    for(int i = 0;i < citations.size();i++){
        if(citations[i] < num) break;
        count++;
    }
    return count;
}

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> list(citations.size());
    sort(citations.begin(), citations.end(), compare);
    for(int i = 0; i < list.size(); i++){
        list[i] = calc(citations, i + 1);
    }
    for(auto i : list){
        cout << i << endl;
    }
    for(int i = 0; i < list.size(); i++){
        if(list[i] >= i + 1) answer = i + 1;
    }
    return answer;
}
