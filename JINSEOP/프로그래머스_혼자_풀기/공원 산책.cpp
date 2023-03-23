#include <string>
#include <vector>
#include <iostream>
using namespace std;

pair<int, int> curr_coord;
void find_start(vector<string> park){
    for(int i = 0; i < park.size(); i++){
        for(int j = 0; j < park[0].size(); j++)
            if(park[i][j] == 'S'){
                curr_coord = {i, j};
                return;
            }
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    find_start(park);
    for(string s : routes){
        bool pass_cmd = false;
        
        switch(s[0]){
            case 'E':
                for(int i = 1; i <= (s[2] - '0'); i++){
                    if((curr_coord.second + i) >= park[0].size() 
                    || park[curr_coord.first][curr_coord.second + i] == 'X'){
                        pass_cmd = true;
                        break;
                    }
                }
                if(!pass_cmd)
                    curr_coord = {curr_coord.first, curr_coord.second + (s[2] - '0')};
                break;
            case 'W':
                for(int i = 1; i <= (s[2] - '0'); i++)
                    if((curr_coord.second - i) < 0 
                    || park[curr_coord.first][curr_coord.second - i] == 'X'){
                        pass_cmd = true;
                        break;
                    }
                if(!pass_cmd)
                    curr_coord = {curr_coord.first, curr_coord.second - (s[2] - '0')};
                break;
            case 'S':
                for(int i = 1; i <= (s[2] - '0'); i++)
                    if((curr_coord.first + i) >= park.size() 
                    || park[curr_coord.first + i][curr_coord.second] == 'X'){
                        pass_cmd = true;
                        break;
                    }
                if(!pass_cmd)
                    curr_coord = {curr_coord.first + (s[2] - '0'), curr_coord.second};
                break;
            case 'N':
                for(int i = 1; i <= (s[2] - '0'); i++)
                    if((curr_coord.first - i) < 0 
                    || park[curr_coord.first - i][curr_coord.second] == 'X'){
                        pass_cmd = true;
                        break;
                    }
                if(!pass_cmd)
                    curr_coord = {curr_coord.first - (s[2] - '0'), curr_coord.second};
                break;
        }
    }
    
    answer.push_back(curr_coord.first);
    answer.push_back(curr_coord.second);
    return answer;
}
