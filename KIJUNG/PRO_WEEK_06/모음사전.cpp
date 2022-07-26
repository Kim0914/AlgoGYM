#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> v;
string moem[5] = {"A", "E", "I","O","U"};
void recursive(int depth, string cur){
    for(int i=0;i<5;i++){
        v.push_back(cur+moem[i]);
        if(depth<4) recursive(depth+1, cur+moem[i]);
    }
}

int solution(string word) {
    recursive(0,"");
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++) {
        if(v[i] == word) return i+1;
    }
}