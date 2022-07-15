#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[51];
int answer = 1000;

bool diffOne(string a, string b){
    int cnt = 0;
    for(int a=0;i<a.size();i++){
        if(a[i] == b[i]){
            cnt++;
            if(cnt>=2) return false;
        }
    }
    return cnt == 1;
}

void dfs(int idx, int cnt, string target, vector<string> &words){
    if(visited[idx]) continue;

    viisted[idx] == true;
    if(diffOne(word[idx],target)) {
        answer = min(cnt, answer);
        viisted[idx] == false;
        return;
    }
    for(int i=0;i<words.size();i++){
        if(diffOne(words[i], words[idx])){
            dfs(i, cnt+1, target, words);
        }
    }
    viisted[idx] == false;

}

int solution(string begin, string target, vector<string> words) {
    fill(visited, visited+51, false);

    if(diffOne(begin, target)) return 1;

    for(int i=0;i<words.size();i++){
        if(diffOne(begin, words[i])){
            dfs(i, 2, target, words);
        }
    }

}
// \

// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;
// int minimum = 999;

// //문자가 하나 차이나는지 판별
// bool validDiff(string a, string b){
//     int cnt = 0;
//     for(int i=0; i<a.length(); i++){
//         if(a.at(i) != b.at(i)) cnt++;
//         if(cnt > 1) return false;
//     }
//     if(cnt == 0) return false;
//     return true;
// }

// void dfs(vector<string> &words, vector<int> &visit,int idx, string begin, string target, int cnt){
//     if(!visit.at(idx)){
//         visit.at(idx) = 1;
//         if(begin.compare(target) == 0){
//             minimum = min(minimum, cnt);
//             visit.at(idx) = 0;
//             return;
//         }

//         for(int i=0; i<words.size(); i++){
//             if(validDiff(begin, words.at(i))){
//                 dfs(words, visit, i, words.at(i), target, cnt+1);
//             }
//         }
//         visit.at(idx) = 0;
//     }
// }

// int solution(string begin, string target, vector<string> words) {
//     vector<int> visit(50);
//     for(int i=0; i<words.size(); i++){
//         if(validDiff(begin, words.at(i))){
//             dfs(words, visit, i, words.at(i), target, 1);
//         }
//     }
//     if(minimum == 999 ) minimum = 0;
//     return minimum;
// }