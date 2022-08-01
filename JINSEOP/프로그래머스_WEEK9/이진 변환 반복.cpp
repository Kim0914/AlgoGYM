#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int z_cnt = 0, con_cnt = 0;
string dec_to_bin(int n) {
    string temp;

    while (n != 0) {
        temp += to_string(n % 2);
        n /= 2;
    }

    reverse(temp.begin(), temp.end());
    return temp;
}

void remove_zero(string& s) {
    string store;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0') store += s[i];
        else z_cnt++;
    }

    s = store;
}

void convert_length(string& s) {
    int target = s.size();
    s = dec_to_bin(target);
}

vector<int> solution(string s) {
    vector<int> answer;

    while (true) {
        con_cnt++;
        remove_zero(s);
        if (s == "1") break;
        convert_length(s);
        if (s == "1") break;
    }

    answer.push_back(con_cnt);
    answer.push_back(z_cnt);

    return answer;
}
