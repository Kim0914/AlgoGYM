#include <iostream>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int N;
int dis[7000][7000];
int cnt[3];

void dc(int size, int x, int y){
    
    if(size < 1) return;
    bool zero, one, mone;
    zero = true;
    one = true;
    mone = true;

    FOR(i,y,y+size){
        FOR(j,x,x+size){
            if(dis[i][j] != 0) zero = false;
            if(dis[i][j] != 1) one = false;
            if(dis[i][j] != -1) mone = false;
        }
    }

    if(zero || one || mone)  cnt[dis[y][x]+1] ++ ;
    else{
        FOR(i,0,3){
            FOR(j,0,3){
                dc(size/3, x + j*size/3, y+i*size/3);
            }
        }
    }
}

int main(void){

    cin >> N;

    FOR(i,1,N+1){
        FOR(j,1,N+1){
            cin >> dis[i][j] ;
        }
    }

    dc(N,1,1);
    
    FOR(j,0,3){
        cout << cnt[j] <<"\n" ;
    }
    return 0;
}