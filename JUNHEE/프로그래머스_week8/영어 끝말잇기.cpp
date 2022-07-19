#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> list;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    list.insert(words[0]);
    int l_size = 1;
    int wrong_idx = -1;
    bool flag = false;
    for(int i = 1; i < words.size(); i++){
        if(words[i-1][words[i-1].size() - 1] != words[i][0]){
            wrong_idx = i;
            break;
        }
        else{
            list.insert(words[i]);
            l_size++;
            if(list.size() != l_size){
                wrong_idx = i;
                break;
            }
        }
            
    }
    if(wrong_idx == -1){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        int people = wrong_idx % n + 1;
        int seq = wrong_idx / n + 1;
        answer.push_back(people);
        answer.push_back(seq);
    }

    return answer;
}
