#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define pii pair<int, int>
#define piii pair<pair<int, int>, int>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool visit_red[4][4], visit_blue[4][4];
pii red_start, blue_start, red_end, blue_end;
int red_blue_bfs(vector<vector<int>> &maze){
    queue<piii> red_q;
    queue<piii> blue_q;
    
    red_q.push({red_start, 0});
    blue_q.push({blue_start, 0});
    // Queue 2개를 사용해서 검사한다면?
    visit_red[red_start.first][red_start.second] = true;
    visit_blue[blue_start.first][blue_start.second] = true;
    // 빨강 파랑 방문처리
    
    bool red_fin = false, blue_fin = false;
    int red_fin_time = 0, blue_fin_time = 0;
    int curr_red_x = 0, curr_blue_x = 0;
    int curr_red_y = 0, curr_blue_y = 0;
    int red_stride = 0, blue_stride = 0;
    
    while(true){
        if(red_q.empty() && blue_q.empty())
            break;
        
        if(!red_q.empty()){
            curr_red_x = red_q.front().first.first;
            curr_red_y = red_q.front().first.second;
            red_stride = red_q.front().second;
            red_q.pop();
        }
        
        if(!blue_q.empty()){
            curr_blue_x = blue_q.front().first.first;
            curr_blue_y = blue_q.front().first.second;
            blue_stride = blue_q.front().second;
            blue_q.pop();
        }
        
        if(curr_red_x == curr_blue_x && curr_red_y == curr_blue_y)
            continue;
        cout << curr_red_x << " " << curr_red_y << " " << curr_blue_x << " " << curr_blue_y << '\n';
        for(int i = 0; i < 4; i++){
            int red_nx = curr_red_x + dx[i];
            int red_ny = curr_red_y + dy[i];
            
            int blue_nx = curr_blue_x + dx[i];
            int blue_ny = curr_blue_y + dy[i];
            
            if(red_nx == curr_blue_x && red_ny == curr_blue_y)
                continue;
            if(blue_nx == curr_red_x && blue_ny == curr_blue_y)
                continue;
            
            if(red_nx == red_end.first && red_ny == red_end.second){
                red_fin = true;
                red_fin_time = red_stride + 1;
                curr_red_x = red_nx;
                curr_red_y = red_ny;
                red_stride = red_fin_time;
            }
            if(blue_nx == blue_end.first && blue_ny == blue_end.second){
                blue_fin = true;
                blue_fin_time = blue_stride + 1;
                curr_blue_x = blue_nx;
                curr_blue_y = blue_ny;
                blue_stride = blue_fin_time;
            }
            
            if(!red_fin){
                if((red_nx >= 0 && red_nx < maze.size()) && (red_ny >= 0 && red_ny < maze[0].size())){
                    if(!visit_red[red_nx][red_ny] && maze[red_nx][red_ny] != 5){
                        red_q.push({{red_nx, red_ny}, red_stride + 1});
                        visit_red[red_nx][red_ny] = true;
                    }
                }
            }
            
            if(!blue_fin){
                if((blue_nx >= 0 && blue_nx < maze.size()) && (blue_ny >= 0 && blue_ny < maze[0].size())){
                    if(!visit_blue[blue_nx][blue_ny] && maze[blue_nx][blue_ny] != 5){
                        blue_q.push({{blue_nx, blue_ny}, blue_stride + 1});
                        visit_blue[blue_nx][blue_ny] = true;
                    }
                }
            }
        }
    }
    
    if(!red_fin || !blue_fin)
        return 0;
    
    return max(red_fin_time, blue_fin_time);
}

int solution(vector<vector<int>> maze) {
    int answer = 0;
    
    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[0].size(); j++){
            if(maze[i][j] == 1)
                red_start = {i, j};
            if(maze[i][j] == 2)
                blue_start = {i, j};
            if(maze[i][j] == 3)
                red_end = {i, j};
            if(maze[i][j] == 4)
                blue_end = {i, j};
        }
    }
    
    answer = red_blue_bfs(maze);
    cout << answer;
    return answer;
}
