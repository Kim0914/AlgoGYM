#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string dec_to_bin(int n, int need_size) {
    string temp = "";

    while (n != 0) {
        temp += to_string(n % 2);
        n /= 2;
    }

    for (int i = temp.size(); i < need_size; i++) 
        temp += '0';

    reverse(temp.begin(), temp.end());
    return temp;
}

void make_code(int n, vector<int> arr1, vector<int> arr2, vector<string>& answer) {
    
    for (int i = 0; i < n; i++) {
        pair<string, string> temp;
        string temp_s = "";

        temp.first = dec_to_bin(arr1[i], n);
        temp.second = dec_to_bin(arr2[i], n);

        for (int j = 0; j < n; j++) {
            if (temp.first[j] == '0' && temp.second[j] == '0') temp_s += '0';
            else temp_s += '1';
        }

        answer.push_back(temp_s);
    }
}

void convert_to_sharp(vector<string>& answer) {
    for (auto& i : answer) {
        for (auto& c : i) {
            if (c == '1') c = '#';
            else c = ' ';
        }
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    make_code(n, arr1, arr2, answer);
    convert_to_sharp(answer);

    return answer;
}
