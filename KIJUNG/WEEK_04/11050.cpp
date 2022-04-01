#include <iostream>

using namespace std;

int N, K;

int pe[11];

int main(void){

    cin >> N >> K;

    pe[0] = 1;
    pe[1] = 1;

    for(int i=2 ; i< 11; i++){
        pe[i] = pe[i-1]*i;
    }

    cout << pe[N]/pe[K]/pe[N-K];


    return 0;
}