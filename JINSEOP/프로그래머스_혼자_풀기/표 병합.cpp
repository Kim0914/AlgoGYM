#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int custom_table[2500];
string string_table[2500];
unordered_map<string, int> cmd_map;
void init_table() {
    for (int i = 0; i < 2500; i++) {
        custom_table[i] = i;
        string_table[i] = "EMPTY";
    }
}

int find_parent(int node) {
    if (custom_table[node] == node)
        return node;

    return custom_table[node] = find_parent(custom_table[node]);
}

void do_merge(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    if (string_table[x] == "EMPTY" && string_table[y] != "EMPTY")
        custom_table[x] = y;
    // 병합 주체는 비어있지만, 병합 대상이 비어있지 않다면?
    // 병합 주체에게 병합 대상을 연결해야 값이 유지된다.
    else
    // 둘 다 비어있거나, 병합 주체가 비어있지 않은 경우엔?
    // 병합 대상을 병합 주체로 연결하면 된다.
        custom_table[y] = x;
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

            vector<int> target_to_unmerge;
            for (int i = 0; i < 2500; i++)
                if (custom_table[find_parent(i)] == parent_of_target)
                    target_to_unmerge.push_back(i);
            // 부모가 같은(병합된) 모든 셀을 병합 해제

            for (int i = 0; i < target_to_unmerge.size(); i++) {
                 custom_table[target_to_unmerge[i]] = target_to_unmerge[i];
                 string_table[target_to_unmerge[i]] = "EMPTY";
            }

            string_table[target_cell] = store;
            // 타겟이 되었던 셀이 값을 가져감
            break;
        }
        case 3: {
            int target_cell = ((stoi(cmds[1]) - 1) * 50) + (stoi(cmds[2]) - 1);
            int parent_of_target = find_parent(target_cell);
            // 병합된 셀일수도 있으니 부모를 찾아가야 함.
            // 병합이 안된 셀이라면, 본인이 부모라서 상관없음
            
            answer.push_back(string_table[parent_of_target]);
            break;
            }
        }
    }

    return answer;
}

int main() {        
    solution({ "UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", 
        "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", 
        "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik", "UPDATE 1 3 group", 
        "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4" });

	return 0;
}
