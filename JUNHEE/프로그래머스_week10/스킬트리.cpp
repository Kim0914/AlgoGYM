#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0; i < skill_trees.size(); i++){
        int idx = 0;
        bool flag = false;
        for(int j = 0; j < skill_trees[i].size(); j++){
            if(skill_trees[i][j] == skill[idx]){
                idx++;
                continue;
            }
            for(int k = idx + 1; k < skill.size(); k++){
                if(skill_trees[i][j] == skill[k]){
                    flag = true;
                }
            }
        }
        if(!flag){
            answer++;
        }
    }
    return answer;
}
