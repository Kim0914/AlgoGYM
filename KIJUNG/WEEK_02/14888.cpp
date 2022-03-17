#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b ;i++)

using namespace std;

int N;
int nums[11];
int op[4];
int m = 1000000000;
int M = -1000000000;

void bt(int degit, int value){
    if(degit == N){
        m = min(m,value);
        M = max(M,value);
    }
    FOR(j,0,4){
        if(op[j] > 0){
            op[j]--;
            switch (j){
                case 0:
                    bt(degit+1, value + nums[degit]);
                    break;
                case 1:
                    bt(degit+1, value - nums[degit]);
                    break;
                case 2:
                    bt(degit+1, value * nums[degit]);
                    break;
                case 3:
                    bt(degit+1, value / nums[degit]);
                    break;
                default:
                    break;
            }
            op[j]++;
        }
    }
}

int main(void){

    cin >> N;
    FOR(i,0,N){
        cin >> nums[i];
    }

    FOR(i,0,4){
        cin >> op[i];
    }

    bt(1, nums[0]);

    cout << M << '\n' << m;
    return 0;
}