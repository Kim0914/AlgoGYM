#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a, b;
    int temp = 999;
    int gcd;
    if(n < m){
        a = m;
        b = n;
    }
    else{
        a = n;
        b = m;
    }
    while(true){
        temp = a % b;
        if(temp == 0){
            gcd = b;
            break;
        }
        a = b;
        b = temp;
    }
    answer.push_back(gcd);
    answer.push_back(n*m/gcd);
    return answer;
}
