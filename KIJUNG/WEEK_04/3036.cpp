#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, tmp, g, first;

int gcd(int a, int b){
    int c;
    while(b != 0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main(void){
    cin >> N;
    cin >> first;
    FOR(i,0,N-1){
        cin >> tmp;
        g = gcd(first, tmp);
        cout << first/g <<"/"<<tmp/g<<"\n";
    }

    return 0;
}