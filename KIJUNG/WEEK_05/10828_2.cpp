#include <iostream>
#include <string>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
string str;
int c =0;
int s[10001];

int main(void){
    cin >> N;

    FOR(i,0,N){
        cin >>str;
        if(str == "push") cin >> s[c++];
        else if(str == "pop") cout << ((c == 0)? -1:s[--c]) << "\n";
        else if(str == "size") cout << c << "\n";
        else if(str== "empty") cout << ((c == 0)? 1:0) << "\n";
        else if(str == "top") cout << ((c == 0)? -1:s[c-1]) << "\n";
    }

    return 0;
}