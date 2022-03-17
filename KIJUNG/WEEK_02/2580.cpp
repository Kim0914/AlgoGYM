#include <iostream>
#include <vector>

#define FOR(i,a,b) for(int i=a;i<b ;i++)

using namespace std;

int check[9];
int sdoku[9][9];

void checking(int x, int y){
    FOR(i,0,9){
        if(sdoku[y][i] != 0) check[sdoku[y][i]-1] = 1;
        if(sdoku[i][x] != 0) check[sdoku[i][x]-1] = 1;    
    }
    FOR(j, y/3*3, y/3*3+3){
        FOR(k, x/3*3, x/3*3+3){
            if(sdoku[j][k] != 0) check[sdoku[j][k]-1] = 1;
        }
    }
}

void bt(int x, int y){
    if(x == 0 && y == 9) {
        FOR(i,0,9){
            FOR(j,0,9){
                cout << sdoku[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    if(sdoku[y][x] == 0){
        vector<int> valid;
        fill(check, check+9, 0);
        checking(x,y);
        FOR(i,0,9){
            if(check[i] == 0) valid.push_back(i+1);
        }
        FOR(i,0,valid.size()){
            sdoku[y][x] = valid[i];
            if(x == 8) bt(0,y+1);
            else bt(x+1, y);
        }
        sdoku[y][x] = 0;
        return;
    }
    if(x == 8) bt(0,y+1);
    else bt(x+1, y);
}

int main(void){

    FOR(i,0,9){
        FOR(j,0,9){
            cin >> sdoku[i][j];
        }
    }

    bt(0,0);
    return 0;
}