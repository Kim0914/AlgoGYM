#include <iostream>
#include <string>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, cnt;
string str;

int main(void){
    cin >> T;

    FOR(i,1,T+1){
        cnt = 0;
        cin >> str;
        FOR(i,0,str.size()){
            if(str.at(i) == '(') cnt ++ ;
            if(str.at(i) == ')') {
                cnt --;
                if(cnt < 0) break;
            }
        }
        if(cnt == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}