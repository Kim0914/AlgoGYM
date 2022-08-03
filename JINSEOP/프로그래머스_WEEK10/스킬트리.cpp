#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, int> skill_map;
void init_map(string skill) {
    int sequence = 1;

    for (int i = 0; i < skill.size(); i++) {
        skill_map[skill[i]] = sequence;
        sequence++;
    }
}

void check_skill_tree(vector<string> skill_trees, int& answer) {
    for (int i = 0; i < skill_trees.size(); i++) {
        int rank = 1; bool possible_tree = true;
        for (int skill = 0; skill < skill_trees[i].size(); skill++) {
            if (skill_map[skill_trees[i][skill]] == 0) continue;
            else {
                if (skill_map[skill_trees[i][skill]] != rank) {
                    possible_tree = false;
                    break;
                }
                if (skill_map[skill_trees[i][skill]] == rank) rank++;
            }
        }
        if(possible_tree) answer++;
    }
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    init_map(skill);
    check_skill_tree(skill_trees, answer);

    return answer;
}
