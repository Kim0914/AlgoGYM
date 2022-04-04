#include <iostream>
#include <stack>
#include <string>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
string str;
stack<int> s;


int main(void){
    cin >> N;

    FOR(i,0,N){
        cin >>str;

        if(str == "push"){
            int tmp;
            cin >> tmp;
            s.push(tmp);
        }
        else if(str == "pop"){
            if(s.empty()){
                cout << -1 << "\n";
            }else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if(str == "size"){
            cout << s.size() << "\n";
        }
        else if(str== "empty"){
            cout << ((s.empty())? 1:0) << "\n";
        }
        else if(str == "top"){
            if(s.empty()){
                cout << -1 << "\n";
            }else cout << s.top() << "\n";
        }
    }

    return 0;
}