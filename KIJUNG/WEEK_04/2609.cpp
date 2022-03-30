#include <iostream>

using namespace std;

int a,b;
int g;

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
    cin >> a >> b;
    g = gcd(a,b);
    cout << g << "\n" << a*(b/g);
    return 0;
}