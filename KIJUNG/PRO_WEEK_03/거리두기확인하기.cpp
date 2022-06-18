#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int dRow[4] = {0,1,0,-1};
int dCol[4] = {1,0,-1,0};
vector<vector<char> > waitroom;
bool visited[5][5];

int DFS(int row, int col, int dist){
    if(waitroom[row][col] == 'P' && dist != 0){
        // cout << "row: " <<row << ", col: " << col << ", dist: " << dist << "\n";
        return 0;
    }

    FOR(i,0,4){
        if(dist >= 2) continue;
        if(row+dRow[i]<0 || row+dRow[i]>=5 || col+dCol[i]<0 || col+dCol[i]>=5) continue;
        if(visited[row+dRow[i]][col+dCol[i]]) continue;
        if(waitroom[row+dRow[i]][col+dCol[i]] == 'X') continue;
        
        visited[row+dRow[i]][col+dCol[i]] = true;
        if(DFS(row+dRow[i], col+dCol[i], dist+1) == 0) return 0;
        visited[row+dRow[i]][col+dCol[i]] = false;
    }

    return 1;

}

int check(vector<vector<char> > &waitroom){
    FOR(i,0,waitroom.size()){
        FOR(j,0,waitroom[i].size()){
            if(waitroom[i][j] == 'P'){
                visited[i][j] = true;
                if(DFS(i,j,0) == 0) return 0;
                visited[i][j] = false;
            }
        }
    }

    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(vector<string> place: places) {
        FOR(i,0,5){
            vector<char> tmp;
            FOR(j,0,5){
                tmp.push_back(place[i][j]);
            }
            waitroom.push_back(tmp);
        }
        answer.push_back(check(waitroom));
        waitroom.clear();
    }
    return answer;
}