#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(long long i=a;i<b;i++)
#define FOR2(i,a,b) for(long long i=a;i>=b;i--)

using namespace std;

long long N, M;
long long h[100000];

void logic(){
    FOR(i,0,N){
        FOR(j,i,N){
            if(h[i] > h[j]) {
                if(h[i]*(j-i)>M) M = h[i]*(j-i);
                break;
            }
            if(j==N-1) if((N-i)*h[i]>M) M = (N-i)*h[i];
        } 
    }
}

void logic_2(){
    FOR2(i,N-1,0){
        FOR2(j,i,0){
            if(h[i] > h[j]) {
                if(h[i]*(i-j)>M) M = h[i]*(i-j);
                break;
            }
            if(j==0) if((i+1)*h[i]>M) M = (i+1)*h[i];
        } 
    }
}


int main(void){

    while(1){
        cin >> N;
        if(N==0) break;
        
        FOR(i,0,N){
            cin >> h[i];
        }

        M = 0;

        logic();
        logic_2();
        cout << M << "\n";

    }

    return 0;
}