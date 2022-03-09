#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define FOR(i,a,b) for(int i = a; i<b ; i++)

using namespace std;

int N, M;
vector<char> tmp;
vector<vector<char> >board;
int minimum = 33;

int changeBox(int x, int y){
    int correctB = 0;
    int totalB = 0;

    FOR(i,y,y+8){
        FOR(j,x,x+8){
            if(board.at(i).at(j) == 'B'){
                totalB++;
                if((i+j)%2) correctB++;
            } 
        }
    }

    int t = totalB - correctB + 32 - correctB; // (흰색 자리에 검정을 놓았을 때 + 검정 자리에 흰색을 놓았을 때) << 0,0 W 바꿀 돌갯수

    return min(t, 64-t);
}

int main(void){
    cin >> N >> M;

    FOR(i,0,N){
        FOR(j,0,M){
            char c;
            cin >> c;
            tmp.push_back(c);
        }
        board.push_back(tmp);
        tmp.clear();
    }

    FOR(i,0,N-7){
        FOR(j,0,M-7){
            minimum = min(minimum,changeBox(j,i));
        }
    }

    cout << minimum;
}