#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());

    do{
        int cnt = 0;
        int need = k;
        for(vector<int> dungeon: dungeons){
            if(need<dungeon[0]) break;
            else{
                need-=dungeon[1];
                cnt++;
            }
        }
        answer=max(cnt, answer);
    }while(next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}