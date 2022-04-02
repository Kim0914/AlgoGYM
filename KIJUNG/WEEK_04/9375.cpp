#include <iostream>
#include <string>
#include <map>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, N;
map<string, int> kind;
int ans;

int main(void){
    cin >> T;

    FOR(i,0,T){
        ans = 1;
        string tmp;
        cin >> N;
        FOR(j,0,N){
            cin >> tmp >> tmp;
            if(kind.find(tmp) != kind.end()){
                kind[tmp]++;
            }else kind[tmp] = 1;
        }
        for(auto clo: kind){
            ans *= (clo.second + 1);
        }
        cout << ans - 1 << "\n";
        kind.clear();
    }
    return 0;
}

//map 사용법!