#include <iostream>

using namespace std;

int N,a,b,g;

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

    for(int j = 0;j<N;j++){
        g = 1;
        cin >> a >> b;
        cout << a*b/gcd(a,b) << "\n";
    }
    
    return 0;
}