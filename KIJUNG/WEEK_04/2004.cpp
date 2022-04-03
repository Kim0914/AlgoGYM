#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

double N, M;

int zero(double n, double divide){
    int total =0;
    int tmp = 0;
    double i = 1;
    while(tmp = (int)(n/pow(divide,i))){
        total += tmp;
        i++;
    }
    return total;
}

int main(void){
    cin >> N >> M;

    cout << min(zero(N,5) - zero(M,5) - zero(N-M,5), zero(N,2) - zero(M,2) - zero(N-M,2));

    return 0;
}