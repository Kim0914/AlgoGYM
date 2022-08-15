#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, string> userList;
void regist_user(vector<string> record) {
    for (auto rec : record) {
        bool is_id = false, is_name = false;
        string uid = "";
        string nickname = "";
        if (rec[0] == 'L') continue;
        for (auto c : rec) {
            if (is_id) {
                if (c == ' ') {
                    is_id = false;
                    is_name = true;
                }
            }
            else {
                if (c == ' ') {
                    is_id = true;
                    is_name = false;
                }
            }
            if(is_id && c != ' ') uid += c;
            if (is_name && c != ' ') nickname += c;
        }
        userList[uid] = nickname;
    }
}

void make_history(vector<string>& answer, vector<string> record) {
    for (auto rec : record) {
        bool is_cmd = true, is_id = false;
        string cmd = "";
        string uid = "";
        for (auto c : rec) {
            if (is_cmd) {
                if (c == ' ') {
                    is_id = true;
                    is_cmd = false;
                }
            }
            else {
                if (c == ' ') break;
            }
            if (is_id && c != ' ') uid += c;
            if (is_cmd && c != ' ') cmd += c;
        }
        if (cmd == "Enter")
            answer.push_back(userList[uid] + "님이 들어왔습니다.");
        if (cmd == "Leave")
            answer.push_back(userList[uid] + "님이 나갔습니다.");
    }
}

vector<string> solution(vector<string> record) {
    vector<string> answer;

    regist_user(record);
    make_history(answer, record);

    return answer;
}
