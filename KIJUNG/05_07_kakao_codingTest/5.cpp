#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

vector<vector<int>> answer;
int firstPoint[50000];
int m;
int colSize, rowSize;

void resetPoint(){
    FOR(i,0,m){
        firstPoint[i] = answer[i][i];
    }
}

void shiftRow(){
    for(int i=answer.size()-1;i>0;i--){
        answer[i].swap(answer[i-1]);
    }
}

void rotate(){
    for(int k=0; k<m; k++){
        for(int i = 1+k; i<rowSize-k; i++){
            answer[i-1][k] = answer[i][k];
        }

        for(int i = 1+k; i<colSize-k; i++){
            answer[rowSize-1-k][i-1] = answer[rowSize-1-k][i];
        }

        for(int i = rowSize-1-k; i>k; i--){
            answer[i][colSize-1-k] = answer[i-1][colSize-1-k];
        }

        for(int i = colSize-1-k; i>1+k; i--){
            answer[k][i] = answer[k][i-1];
        }

        answer[k][1+k] = firstPoint[k];
    }
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    FOR(i,0,rc.size()){
        vector<int> tmp;
        FOR(j,0,rc[0].size()){
            tmp.push_back(rc[i][j]);
            if(i==j) firstPoint[i] = rc[i][j];
        }
        answer.push_back(tmp);
    }

    colSize = answer[0].size();
    rowSize = answer.size();
    // m = min(rowSize, colSize)/2;
    m=1;

    FOR(i,0,operations.size()){
        if(operations[i] == "Rotate") rotate();
        else if(operations[i] == "ShiftRow") shiftRow();
        resetPoint();

        // FOR(i,0,rc.size()){
        //     FOR(j,0,rc[0].size()){
        //         cout << answer[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }

    // rotate();
    
    return answer;
}