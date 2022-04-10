#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, n, tmp;
string str;
char c;



int main(void){
    cin >> T;

    FOR(i,0,T){
        deque<int> d;
        bool forward = true;
        bool isError = false;
        cin >> str;
        cin >> n;
        cin >> c;
        FOR(j,0,n){
            cin >> tmp;
            cin >> c;
            d.push_back(tmp);
        }
        if(n==0) cin >> c;
        FOR(j,0,str.size()){
            if(str.at(j) == 'R') forward = !forward;
            if(str.at(j) == 'D'){
                if(d.empty()){
                    cout << "error\n";
                    isError = true;
                    break;
                }
                if(forward) d.pop_front();
                else d.pop_back();
            }
        }
        
        if(isError) continue;

        cout << "[";            
        if(forward) while(!d.empty()){
            cout << d.front();
            d.pop_front();
            if(!d.empty()) cout << ",";
        }
        else while(!d.empty()){
            cout << d.back();
            d.pop_back();
            if(!d.empty()) cout << ",";
        }
        cout << "]\n";

    }

    return 0;
}