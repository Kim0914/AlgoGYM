#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define pii pair<int, int>

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool visit[51][51];
vector<vector<pii>> hole_vec, puzzle_vec;
void clear_visit(vector<vector<int>> &target_board){
    for(int i = 0; i < target_board.size(); i++)
        for(int j = 0 ; j < target_board[0].size(); j++)
            visit[i][j] = false;
}

void standardize(vector<pii> &target){
    int min_x = target[0].first;
    int min_y = target[0].second;
    // 가장 작은 좌표 => 가장 왼쪽 위
    // 가장 왼쪽 위 좌표를 (0, 0)으로 표준화하자.
    
    for(int i = 1; i < target.size(); i++){
        min_x = min(min_x, target[i].first);
        min_y = min(min_y, target[i].second);
    }
    
    for(int i = 0; i < target.size(); i++){
        target[i].first -= min_x;
        target[i].second -= min_y;
    }
}

int compare_coordinate(vector<pii> hole, vector<pii> puzzle){
    standardize(hole);
    standardize(puzzle);
    
    if(hole.size() != puzzle.size())
        return 0;
    // 둘이 길이가 다르면 애초에 다른 조각임
    
    int same_count = 0;
    for(int i = 0; i < hole.size(); i++){
        for(int j = 0; j < puzzle.size(); j++){
            if(hole[i].first == puzzle[i].first && hole[i].second == puzzle[i].second){
                same_count++;
                break;
            // 멈추는 이유는, 두 배열에 저장된 좌표는 같으나 보드가 돌아갔을 때
            // 순서가 다를 수가 있기 때문에, 같은 좌표가 등장하면 멈춘다.
            }
        }
    }
    
    if(same_count == hole.size())
        return same_count; // 동일 좌표의 수가 같으면, 맞는 조각!
    else
        return 0;
}

vector<vector<int>> rotate_board(vector<vector<int>> &game_board){
    vector<vector<int>> board_to_return(game_board[0].size(), vector<int>(game_board.size(), 0));
    
    for(int i = 0; i < game_board.size(); i++)
        for(int j = 0; j < game_board[0].size(); j++)
            board_to_return[j][(game_board.size() - 1) - i] = game_board[i][j];
    
    return board_to_return;
}

void mark_board(vector<vector<int>> &game_board, vector<pii> coordinates){
    for(int i = 0; i < coordinates.size(); i++){
        int x = coordinates[i].first;
        int y = coordinates[i].second;
        
        game_board[x][y] = 1;
    }
}

vector<pii> bfs(int st_x, int st_y, vector<vector<int>> &target_board){
    queue<pii> bfs_q;
    vector<pii> coord_list;
    bfs_q.push({st_x, st_y});
    visit[st_x][st_y] = true;
    coord_list.push_back({st_x, st_y});
    
    bool isPuzzle = (target_board[st_x][st_y] == 1) ? true : false;

    while(!bfs_q.empty()){
        int curr_x = bfs_q.front().first;
        int curr_y = bfs_q.front().second;
        bfs_q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = curr_x + dx[i];
            int ny = curr_y + dy[i];
            
            if((nx >= 0 && nx < target_board.size()) && (ny >= 0 && ny < target_board[0].size())){
                if(!visit[nx][ny]){
                    if(target_board[nx][ny] == 0 && isPuzzle)
                        continue;
                    if(target_board[nx][ny] == 1 && !isPuzzle)
                        continue;
                    
                    bfs_q.push({nx, ny});
                    visit[nx][ny] = true;
                    coord_list.push_back({nx, ny});
                }
            }
        }
    }
    
    return coord_list;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    for(int i = 0; i < table.size(); i++)
        for(int j = 0 ; j < table[0].size(); j++)
            if(!visit[i][j] && table[i][j])
                // 퍼즐 정보 벡터에 저장
                puzzle_vec.push_back(bfs(i, j, table));
    
    int rotation_cnt = 4; // 최대 4회 회전 가능
    while(rotation_cnt--){
    // 퍼즐 조각을 돌리는 것이 아닌, 보드의 공간을 돌리는 것이 핵심!
        clear_visit(game_board);
        for(int i = 0; i < game_board.size(); i++)
            for(int j = 0 ; j < game_board[0].size(); j++)
                if(!visit[i][j] && !game_board[i][j])
                // 퍼즐을 끼울 빈 공간 벡터에 저장
                    hole_vec.push_back(bfs(i, j, game_board));
        // 공간을 돌리기 때문에 매번 벡터를 빈 공간으로 만들어 주어야 함
      
        for(int i = 0; i < puzzle_vec.size(); i++){
            for(int j = 0; j < hole_vec.size(); j++){
                int right_piece = compare_coordinate(puzzle_vec[i], hole_vec[j]);
              
                answer += right_piece;
                if(right_piece != 0){
                    mark_board(game_board, hole_vec[j]);
                    // 맞아 떨어진 조각은 채워넣어야 함
                    puzzle_vec.erase(puzzle_vec.begin() + i);
                    hole_vec.erase(hole_vec.begin() + j);
                    // 다 쓴 조각과 공간은 벡터에서 삭제
                    i--;
                    // erase하면 iterator가 뒤로 밀림. 하나 빼주어야 함
                    break;
                }
                // 맞는 조각을 찾았으면 해당 공간은 더 진행할 필요가 없음.
            }
        }
        
        game_board = rotate_board(game_board);
    }
    
    return answer;
}
