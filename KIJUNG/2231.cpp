#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
string s;

int sol(){
    for(int i=0; i<1000000; i++){
        int sum = 0;
        s = to_string(i);
        for(int j =0;j<s.length();j++){
            sum += s.at(j)-48;
           
        }
        if(sum + i == N){
            return i;
        }
        
    }
    return 0;
}

int main(void){
    // input
    cin >> N;
    s = to_string(N);

    cout << sol() <<endl;

    return 0;
}