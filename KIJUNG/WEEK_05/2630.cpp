#include <iostream>

#define FOR(i,a,b) for(int i =a;i<b;i++)

using namespace std;

int N;
int nums[129][129];
int store[2];


int dc(int size, int x, int y, int color){
    if(size == 1) {
        if(nums[x][y] == color) return 1;
        else return 0;
    }

    int cnt = 0;
    FOR(i,0,2){
        FOR(j,0,2){
            cnt += dc(size/2, i*size/2+x, j*size/2+y, color);   
        }
    }

    if(cnt == size*size) cnt = 1;
    // cout << "[" << size << ", " << x << ", " << y << ", " << color << "] cnt: " << cnt << "\n"; 
    return cnt;
}

int main(void){
    cin >> N;

    FOR(i,1,N+1){
        FOR(j,1,N+1){
            cin >> nums[i][j];
        }
    }


    cout << dc(N, 1, 1, 0) << "\n";
    cout << dc(N, 1, 1, 1) << "\n";

    return 0;
}

//