#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int key = 0;
bool cmp(string a, string b){
    if(a[key] == b[key])
        return a < b;
    else
        return a[key] < b[key];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    key = n;
    
    sort(strings.begin(), strings.end(), cmp);
    answer = strings;
    return answer;
}
