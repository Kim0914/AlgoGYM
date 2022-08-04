#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < arr1.size(); i++){
        int temp = arr1[i]|arr2[i];
        string t_ans = "";
        for(int j = 0; j < arr1.size(); j++){
            if(temp % 2 == 1)
                t_ans += '#';
            else
                t_ans += ' ';
            temp /= 2;
        }
        reverse(t_ans.begin(), t_ans.end());
        answer.push_back(t_ans);
    }
    return answer;
}
