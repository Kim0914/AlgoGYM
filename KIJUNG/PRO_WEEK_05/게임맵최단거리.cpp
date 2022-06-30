#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int visited[100][100];
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    queue<pair<int, int> > q;
    fill(&visited[0][0], &visited[99][100], 0);

    q.push(make_pair(0,0));
    visited[0][0] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nextX = x+dx[i];
            int nextY = y+dy[i];

            if(nextX<0 || nextX>=maps.size() || nextY<0 || nextY>=maps[0].size()) continue;
            if(maps[nextX][nextY] == 0 || visited[nextX][nextY] > 0) continue;
            visited[nextX][nextY] = visited[x][y]+1;
            q.push(make_pair(nextX,nextY));
        }
    }

    answer = visited[maps.size()-1][maps[0].size()-1];
    if(answer == 0) answer = -1;

    return answer;
}