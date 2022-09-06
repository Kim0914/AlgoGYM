#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>> map(land.size(), vector<int>(4));
    for(int i = 0; i < 4; i++){
        map[0][i] = land[0][i];
    }
    for(int i = 1; i < land.size(); i++){
        for(int j = 0; j < 4; j++){
            int temp = land[i][j];
            for(int k = 0; k < 4; k++){
                if(j != k){
                    if(temp + map[i-1][k] > map[i][j])
                        map[i][j] = map[i-1][k] + temp;
                }
            }
        }
    }
    int last = map.size() - 1;
    answer = max({map[last][0], map[last][1], map[last][2], map[last][3]});
    return answer;
}
