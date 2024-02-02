#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int custom_table[2500];
string string_table[2500];
unordered_map<string, int> cmd_map;
void init_table() {
    for (int i = 0; i < 2500; i++)
        custom_table[i] = i;
}

int find_parent(int node) {
    return custom_table[node];
}

void do_merge(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    if (x != y) {
    // 이 부분이 merge의 핵심이 된다.
        for (int i = 0; i < 2500; i++)
            if (custom_table[i] == y)
                custom_table[i] = x;

        if (string_table[x] == "" && string_table[y] != "")
            string_table[x] = y;
        else
            string_table[y] = x;
    }
}

vector<string> parse_command(string cmd) {
    vector<string> cmds(5, "");
    string temp = "";
    int cnt = 0;

    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i] == ' ') {
            cmds[cnt] = temp;
            temp = "";
            cnt++;

            continue;
        }

        temp += cmd[i];
    }

    cmds[cnt] = temp;
    return cmds;
}

int tokenize_command(string target) {
    cmd_map["UPDATE"] = 0; cmd_map["MERGE"] = 1; cmd_map["UNMERGE"] = 2; cmd_map["PRINT"] = 3;
    return cmd_map[target];
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;

    init_table();
    vector<string> cmds; // 명령 파싱용
    for (int i = 0; i < commands.size(); i++) {
        cmds = parse_command(commands[i]);

        int token = tokenize_command(cmds[0]);
        switch (token)
        {
        case 0:
            if (cmds[3] == "") {
                // update value value의 형식
                for (int i = 0; i < 2500; i++)
                    if (string_table[i] == cmds[1])
                        string_table[i] = cmds[2];
            }
            else {
                // update r c value의 형식
                int target_cell = ((stoi(cmds[1]) - 1) * 50) + (stoi(cmds[2]) - 1);
                int parent_of_target = find_parent(target_cell);
                string_table[parent_of_target] = cmds[3];
                // 병합된 셀이라면 부모의 값을 바꿔야 함
            }
            break;
        case 1: {
            // MERGE
            int src_cell = ((stoi(cmds[1]) - 1) * 50) + (stoi(cmds[2]) - 1);
            int dest_cell = ((stoi(cmds[3]) - 1) * 50) + (stoi(cmds[4]) - 1);
            do_merge(src_cell, dest_cell);
            break;
        }
        case 2:
        {
            // UNMERGE
            int target_cell = ((stoi(cmds[1]) - 1) * 50) + (stoi(cmds[2]) - 1);
            int parent_of_target = find_parent(target_cell);
            string store = string_table[parent_of_target];

            for (int i = 0; i < 2500; i++)
                if (custom_table[i] == parent_of_target) {
                    custom_table[i] = i;
                    string_table[i] = "";
                }
            // 부모가 같은(병합된) 모든 셀을 병합 해제

            string_table[target_cell] = store;
            // 타겟이 되었던 셀이 값을 가져감
            break;
        }
        case 3: {
            int target_cell = ((stoi(cmds[1]) - 1) * 50) + (stoi(cmds[2]) - 1);
            int parent_of_target = find_parent(target_cell);
            // 병합된 셀일수도 있으니 부모를 찾아가야 함.
            // 병합이 안된 셀이라면, 본인이 부모라서 상관없음

            if (string_table[parent_of_target] == "")
                answer.push_back("EMPTY");
            else
                answer.push_back(string_table[parent_of_target]);
            break;
        }
        }
    }

    return answer;
}

int main() {        
    solution({ "MERGE 1 1 2 2", "PRINT 1 1" });

	return 0;
}
