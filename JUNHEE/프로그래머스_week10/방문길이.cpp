#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

struct point{
    int x;
    int y;
    int nx;
    int ny;
};


int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5;
    
    vector<point> us;
    
    for(int i = 0; i < dirs.size(); i++){
        char dir = dirs[i];
        bool flag = false;
        point temp;
        switch (dir){
            case 'U':
                if(x == 0) continue;
                temp.x = x;
                temp.y = y;
                temp.nx = x - 1;
                temp.ny = y;
                x--;
                for(int v = 0; v < us.size(); v++){
                    if(us[v].x == temp.x && us[v].y == temp.y && us[v].nx == temp.nx && us[v].ny == temp.ny){
                        flag = true;
                        break;
                    }
                    else if(us[v].x == temp.nx && us[v].y == temp.ny && us[v].nx == temp.x && us[v].ny == temp.y){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    us.push_back(temp);
                }
                break;
            case 'D':
                if(x == 10) continue;
                temp.x = x;
                temp.y = y;
                temp.nx = x + 1;
                temp.ny = y;
                x++;
                for(int v = 0; v < us.size(); v++){
                    if(us[v].x == temp.x && us[v].y == temp.y && us[v].nx == temp.nx && us[v].ny == temp.ny){
                        flag = true;
                        break;
                    }
                    else if(us[v].x == temp.nx && us[v].y == temp.ny && us[v].nx == temp.x && us[v].ny == temp.y){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    us.push_back(temp);
                }
                break;
            case 'R':
                if(y == 10) continue;
                temp.x = x;
                temp.y = y;
                temp.nx = x;
                temp.ny = y + 1;
                y++;
                for(int v = 0; v < us.size(); v++){
                    if(us[v].x == temp.x && us[v].y == temp.y && us[v].nx == temp.nx && us[v].ny == temp.ny){
                        flag = true;
                        break;
                    }
                    else if(us[v].x == temp.nx && us[v].y == temp.ny && us[v].nx == temp.x && us[v].ny == temp.y){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    us.push_back(temp);
                }
                break;
            case 'L':
                if(y == 0) continue;
                temp.x = x;
                temp.y = y;
                temp.nx = x;
                temp.ny = y - 1;
                y--;
                for(int v = 0; v < us.size(); v++){
                    if(us[v].x == temp.x && us[v].y == temp.y && us[v].nx == temp.nx && us[v].ny == temp.ny){
                        flag = true;
                        break;
                    }
                    else if(us[v].x == temp.nx && us[v].y == temp.ny && us[v].nx == temp.x && us[v].ny == temp.y){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    us.push_back(temp);
                }
                break;
        }
    }
    answer = us.size();
    return answer;
}
