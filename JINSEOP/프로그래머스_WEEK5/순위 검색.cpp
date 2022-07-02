#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> string_parse(string str) {
    vector<string> res;
    string temp = "";

    for (auto pars : str) {
        if (pars == ' ') {
            if (temp != "and") res.push_back(temp);
            temp = "";
        }
        else temp += pars;
    }

    res.push_back(temp);
    return res;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, vector<int>> applicants;

    for (auto data : info) {
        vector<string> key = string_parse(data);
        for (int i = 0; i < 16; i++) {
            string temp = "";
            for (int j = 0; j < 4; j++) {
                if (i & (1 << j)) temp += "-";
                else temp += key[j];
            }
            applicants[temp].push_back(stoi(key[4]));
        }
    }

    for (auto& iter : applicants) sort(iter.second.begin(), iter.second.end());

    for (auto q : query) {
        vector<string> key = string_parse(q);
        string quest = key[0] + key[1] + key[2] + key[3];
        vector<int> res = applicants[quest];

        int cnt = res.end() - lower_bound(res.begin(), res.end(), stoi(key[4]));
        answer.push_back(cnt);
    }

    return answer;
}
