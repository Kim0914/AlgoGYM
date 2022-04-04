#include <iostream>
#include <vector>
#include <string>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int K;
int sum = 0;
vector<int> v;

int main(void){
    cin >> K;
    FOR(i,0,K){
        int tmp;
        cin >> tmp;
        if(tmp != 0){
            v.push_back(tmp);
        }else v.pop_back();
    }
    
    while(!v.empty()){
        sum += v.back();
        v.pop_back();
    }

    cout << sum;

    return 0;
}