#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<char, int> X_map;
unordered_map<char, int> Y_map;
string res = "";
void init_map(string X, string Y){
    for(char c : X)
        X_map[c]++;
    for(char c : Y)
        Y_map[c]++;
}

void compare_umap(){
    int iter = 0;
    
    for(int i = 0; i < 10; i++){
        char key = i + '0';

        if((X_map[key] != 0) && (Y_map[key] != 0)){
            iter = min(X_map[key], Y_map[key]);
        
            for(int k = 0; k < iter; k++)
                res += key;
        }
    }
}

void only_zero(){
    int size = res.size();
    
    if(res[0] == '0')
        res = "0";
}

string solution(string X, string Y) {
    string answer = "";
    
    init_map(X, Y);
    compare_umap();
    
    if(res == "")
        answer = "-1";
    else{
        sort(res.begin(), res.end(), greater<>());
        only_zero();
        answer = res;
    }
    
    return answer;
}
