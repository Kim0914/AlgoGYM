#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> num;
    string temp_num = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' '){
            temp_num += s[i];
        }
        else if(s[i] == ' '){
            num.push_back(stoi(temp_num));
            temp_num = "";
        }
    }
    num.push_back(stoi(temp_num));
    int max = *max_element(num.begin(), num.end());
    int min = *min_element(num.begin(), num.end());
    answer += to_string(min);
    answer += ' ';
    answer += to_string(max);
    return answer;
}
