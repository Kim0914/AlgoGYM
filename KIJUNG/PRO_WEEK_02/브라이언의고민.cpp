#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<string> word2;
bool valid = true;

bool islower(char c){
    return c>='a' && c <= 'z';
}

//규칙2를 기반으로 짜르기
void cut(string sent){
    cout << "sent: " <<sent<< "\n";
    if(islower(sent[0])){
        if(count(sent.begin(), sent.end(), sent[0]) == 2){
            int idx = find(sent.begin()+1, sent.end(), sent[0])-sent.begin();
            word2.push_back(sent.substr(1,idx-1));
            if(sent.size()-idx-1>0) cut(sent.substr(idx+1, sent.size()-idx));
        }
    }
    else{
        for(char c: sent){
            if(islower(c)) {
                int cnt = count(sent.begin(), sent.end(), c);
                if(cnt == 2){
                    int idx = find(sent.begin()+1, sent.end(), c)-sent.begin();
                    word2.push_back(sent.substr(0,idx));
                    if(sent.size()-idx-1>0) cut(sent.substr(idx, sent.size()-idx));
                    return;
                }
                else if(cnt == 1){
                    int idx = find(sent.begin(), sent.end(), c)-sent.begin();
                    word2.push_back(sent.substr(0,idx-1));
                    if(sent.size()-idx-1>0) cut(sent.substr(idx-1, sent.size()-idx+1));
                    return;
                }
            }
        }

    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";
    cut(sentence);
    return answer;
}

int main(void){
    cut("브라이언 고민 공유 금지");

    for(string s: word2){
        cout << s << "\n";
    }

    return 0;
}

