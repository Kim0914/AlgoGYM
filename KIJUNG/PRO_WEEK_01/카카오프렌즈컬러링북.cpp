#include <vector>
#include <algorithm>
#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int component;
int max_size_of_one_area;
int visited[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int cnt;

void dfs(int y, int x, int m, int n, int color, vector<vector<int> > &picture){
    if(y<0 || y>m-1 || x<0 || x>n-1) return;
    if(visited[y][x] == 0 && picture[y][x] == color){
        visited[y][x] = component;
        cnt++;
        FOR(i,0,4){
            dfs(y+dy[i], x+dx[i], m, n, color, picture);
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    component = 0;
    max_size_of_one_area = 0;

    fill(visited[0], visited[101], 0);

    FOR(i,0,m){
        FOR(j,0,n){
            if(picture[i][j] != 0 && visited[i][j] == 0){
                cnt=0;
                component++;
                dfs(i,j,m,n,picture[i][j],picture);
                max_size_of_one_area = max(cnt, max_size_of_one_area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = component;
    answer[1] = max_size_of_one_area;
    return answer;
}