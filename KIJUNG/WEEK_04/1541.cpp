#include <iostream>
#include <string>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

string str;
int cur = 0;
bool f = false;
int m = 0;

int main(void){
    cin >> str;

    FOR(i,0,str.size()){
        if(i == str.size()-1 || str[i] == '-' || str[i] == '+'){
            if(i == str.size()-1) i++;

            int tmp = stoi(str.substr(cur, i-cur));
            cur = i+1;

            if(f) m-=tmp;
            else m+=tmp;
            if(str[i] == '-') f = true;
        }
    }

    cout << m;
    return 0;
}