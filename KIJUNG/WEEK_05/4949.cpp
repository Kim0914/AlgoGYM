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
        FOR(i,0,str.size()){
            if(str.at(i) == '(') s.push_back('(');
            if(str.at(i) == ')') {
                if(s.empty()) s.push_back('[');
                if(s.back()!='(') break;
                else s.pop_back();    
            }
            if(str.at(i) == '[') s.push_back('[');
            if(str.at(i) == ']') {
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