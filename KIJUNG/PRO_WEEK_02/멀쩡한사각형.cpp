#include <math.h>
#include <iostream>

using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w,int h) {
    long long answer =(long long)w*h - (w+h-gcd(w,h));
    
    return answer;
}