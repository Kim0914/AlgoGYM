#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;
int ans;
int N;
int board[16];

bool check(int num){
    for(int i=0; i<num; i++){
        if(board[i] == board[num] || (board[num]-board[i] == (num - i))){
            return false;
        }
    }
    return true;
}

void search(int num){
    if(num == N) ans++;

    else{
        for(int i=0; i<N; i++){
            board[num] = i;
            if(check(num)){
                search(num+1);
            }
        }
    }
}


int main(void){
    memset(board, 0, sizeof(board));
    cin >> N;

    search(0);
    printf("%d\n", ans);

}