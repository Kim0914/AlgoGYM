#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, pair<int, string>> babbling_map;
void fill_map() {
    babbling_map["aya"] = {3, "1"};
    babbling_map["ye"] = {2, "2"};
    babbling_map["woo"] = {3, "3"};
    babbling_map["ma"] = {2, "4"};
}

int solution(vector<string> babbling) {
    int answer = 0;

    fill_map();

    for (string s : babbling) {
        int len = 0;
        string partial_bab = "", validator = "";

        for (int i = 0; i < s.size(); i++) {
            partial_bab += s[i];

            if (babbling_map[partial_bab].first != 0) {
                len += babbling_map[partial_bab].first;
                validator += babbling_map[partial_bab].second;
                partial_bab = "";

                if (validator.size() > 1) {
                    if (validator[validator.size() - 2] == validator[validator.size() - 1]) {
                        len = 0;
                        break;
                    }
                }
            }
        }

        if (len == s.size())
            answer++;
    }

    return answer;
}
