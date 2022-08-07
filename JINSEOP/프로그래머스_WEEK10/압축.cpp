#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> dictionary;
string alphabet[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L",
"M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
void init_dict() {
    string alpha = "A";
    for (int i = 1; i < 27; i++)
        dictionary[alphabet[i-1]] = i;
}

vector<int> LZW_comp(string msg) {
    vector<int> result;
    int iter = 0, part_size = 1, add_cnt = 27;

    while (iter < msg.size()) {
        part_size = 1;

        while (dictionary[msg.substr(iter, part_size)] != 0) {
            part_size++;
            if (iter + part_size > msg.size()) break;
        }

        string to_print = msg.substr(iter, part_size - 1);
        string to_store = msg.substr(iter, part_size);
        iter = iter + to_print.size();
        result.push_back(dictionary[to_print]);
        dictionary[to_store] = add_cnt;
        add_cnt++;
    }
    
    return result;
}

vector<int> solution(string msg) {
    vector<int> answer;

    init_dict();
    answer = LZW_comp(msg);

    return answer;
}
