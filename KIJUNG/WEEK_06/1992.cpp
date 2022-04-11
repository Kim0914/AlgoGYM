#include <iostream>
#include <string>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int N;
int dis[65][65];
string str;

void dc(int size, int x, int y){
    
    // cout << "n: " << size<<" x: " <<x<<" ,y: "<<y <<"\n";
    if(size < 1) return;
    bool zero, one;
    zero = true;
    one = true;

    FOR(i,y,y+size){
        FOR(j,x,x+size){
            if(dis[i][j]) zero = false;
            if(!dis[i][j]) one = false;
        }
    }

    if(zero || one) cout << dis[y][x];
    else{
        cout << "(";
        dc(size/2, x, y);
        dc(size/2, x+size/2, y);

        dc(size/2, x, y + size/2);

        dc(size/2, x + size/2, y + size/2);

        cout << ")";
    }

}

int main(void){

    cin >> N;

    FOR(i,1,N+1){
        cin >> str;
        FOR(j,0,str.size()){
            dis[i][j+1] = str.at(j) - 48;
        }
    }

    dc(N,1,1);

    return 0;
}