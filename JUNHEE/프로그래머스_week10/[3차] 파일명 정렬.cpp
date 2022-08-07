#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct file{
    string HEAD = "";
    int num = 0;
    int idx;
};

bool compare(file& a, file& b){
    if(a.HEAD == b.HEAD){
        if(a.num == b.num)
            return a.idx < b.idx;
        else
            return a.num < b.num;
    } else {
        return a.HEAD < b.HEAD;
    }
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<file> f_list;
    for(int i = 0; i < files.size(); i++){
        file temp;
        temp.idx = i;
        string t_file = "";
        for (int j = 0; j < files[i].length(); j++) {
            t_file += tolower(files[i][j]);
        }
        int is_num = 0;
        for(int j = 0; j < t_file.size(); j++){
            if(t_file[j] < '0' || t_file[j] > '9'){
                temp.HEAD += t_file[j];
            }else{
                is_num = j;
                break;
            }
        }
        for(int j = is_num; j < t_file.size(); j++){
            if('0' <= t_file[j] && t_file[j] <= '9'){
                temp.num *= 10;
                temp.num += t_file[j] - '0';
            }else{
                break;
            }
        }
        f_list.push_back(temp);
    }
    sort(f_list.begin(), f_list.end(), compare);
    for(auto i : f_list){
        answer.push_back(files[i.idx]);
    }
    return answer;
}
