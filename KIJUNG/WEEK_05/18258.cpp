#include <iostream>
#include <string>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int N;
string str;
int nums[2000001];

int f = 0;
int e = 0;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    FOR(i,0,N){
        cin >> str;
        if(str == "push"){
            cin >> nums[e++];
        }
        else if(str == "pop"){
            if(f==e) cout << -1 << "\n";
            else cout << nums[f++] << "\n";
        }
        else if(str == "size") cout << e-f << "\n";
        else if(str == "empty"){
            if(f==e) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(str == "front"){
            if(f==e) cout << -1 << "\n";
            else cout << nums[f] << "\n";
        }
        else if(str == "back"){
            if(f==e) cout << -1 << "\n";
            else cout << nums[e-1] << "\n";
        }
    }

    return 0;
}