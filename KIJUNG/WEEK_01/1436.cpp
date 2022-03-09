#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;
int N;
string tmp;
string want = "666";
int cnt = 0;

void returnCnt(int n){
    tmp = to_string(n);
    
    for(int i =0; i<tmp.length()-2; i++){
        if(tmp.substr(i,3) == want) {
            cnt++;
            break;
        }
    }
}

int main(void){
    cin >> N;

    for(int i=666; i<3000000; i++){
        returnCnt(i);
        if(cnt == N){
            cout << tmp;
            break;
        }
    }

    return 0;
}