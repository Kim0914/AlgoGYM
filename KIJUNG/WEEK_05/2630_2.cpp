#include <iostream>

#define FOR(i,a,b) for(int i =a;i<b;i++)

using namespace std;

int N;
int nums[129][129];
int store[2];


void dc(int size, int x, int y){
    bool zero = true;
    bool one = true;
    FOR(i,x,x+size){
        FOR(j,y,y+size){
            if(nums[i][j] == 1) zero = false;
            if(nums[i][j] == 0) one = false;
        }
    }

    if(zero) {
        store[0]++;
        return;
    }
    if(one){
        store[1]++;
        return;
    }

    FOR(i,0,2){
        FOR(j,0,2){
            dc(size/2, x+i*size/2, y+j*size/2);
        }
    }

}

int main(void){
    cin >> N;

    FOR(i,1,N+1){
        FOR(j,1,N+1){
            cin >> nums[i][j];
        }
    }

    dc(N,1,1);

    FOR(i,0,2){
        cout << store[i] << "\n";
    }

    return 0;
}