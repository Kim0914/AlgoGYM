#include <iostream>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

vector<char> s;
string str;

int main(void){
    while (true){
        getline(cin, str);

        if(str == ".")  break;

        for(char c: str){
            if(c == '(') s.push_back(c);
            else if(c == ')') {
                if(s.empty()) s.push_back('[');
                if(s.back()!='(') break;
                else s.pop_back();    
            }
            else if(c == '[') s.push_back(c);
            else if(c == ']') {
                if(s.empty()) s.push_back('(');
                if(s.back()!='[') break;
                else s.pop_back();    
            }
        }
        if(s.empty()) cout << "yes\n";
        else cout << "no\n";
        s.clear();
    }

    return 0;
}

//줄 단위로 입력 받기(공백까지 입력 받을 수 있음) 
//getline(cin, str);