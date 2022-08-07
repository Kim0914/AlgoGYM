#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct files_struct{
    string org;
    string head;
    int number;
};

bool cmp(files_struct a, files_struct b) {
    string temp_a = "", temp_b = "";
    for (int i = 0; i < a.head.size(); i++)
        temp_a += tolower(a.head[i]);
    for (int i = 0; i < b.head.size(); i++)
        temp_b += tolower(b.head[i]);

    if (temp_a == temp_b)
        return a.number < b.number;

    return temp_a < temp_b;
}

vector<files_struct> filed_file;
int convert_string(string str) {
    int res = 0, ten_key = 1;

    for (int i = str.size() - 1; i >= 0; i--) {
        res += (str[i] - '0') * ten_key;
        ten_key *= 10;
    }

    return res;
}

void parse_file(vector<string> files) {
    for (auto i : files) {
        string temp = "";
        files_struct temp_st;
        int idx = 0;

        temp_st.org = i;
        for (int k = 0; k < i.size(); k++) {
            if (i[k] >= '0' && i[k] <= '9') {
                idx = k;
                break;
            }
            temp += i[k];
        }

        temp_st.head = temp; temp = "";

        for (int k = idx; k < i.size(); k++) {
            if (i[k] < '0' || i[k] > '9') break;
            temp += i[k];
        }

        temp_st.number = convert_string(temp);
        filed_file.push_back(temp_st);
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    parse_file(files);
    stable_sort(filed_file.begin(), filed_file.end(), cmp);

    for (auto i : filed_file) answer.push_back(i.org);
    return answer;
}
