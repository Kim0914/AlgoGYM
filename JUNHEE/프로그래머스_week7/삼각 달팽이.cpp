#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> map(n, vector<int> (n, -1));
    int num = 1;
    int dx[3] = {1,0,-1};
    int dy[3] = {0,1,-1};
    bool flag = true;
    int idx = 0;
    int x = 0, y = 0;
    map[x][y] = num;
    num++;
    for(int i = 0; i < n * (n+1) / 2; i++){
        int temp_dx = dx[idx%3], temp_dy = dy[idx%3];
        while(true){
            if(x + temp_dx >= 0 && x + temp_dx < n && y + temp_dy >= 0 && y + temp_dy < n){
                if(map[x + temp_dx][y + temp_dy] == -1){
                    if(num > n * (n+1) / 2){
                        break;
                    }
                    x = x + temp_dx; y = y + temp_dy;
                    map[x][y] = num;
                    num++;
                    
                }else{
                    if(map[x + 1][y] != -1 && map[x][y + 1] != -1 && map[x - 1][y - 1] != -1)
                        flag = false;
                    break;
                }
            }
            else
                break;
        }
        idx++;
    }
    for(auto i : map){
        for(auto j : i){
            if(j == -1) break;
            answer.push_back(j);
        }
    }
    return answer;
}
