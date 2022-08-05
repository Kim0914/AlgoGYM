#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    string listen = "";
    int ans_time = 0;
    for(int i = 0; i < m.size() - 1; i++){
        if(m[i+1] == '#'){
            listen += m[i] + 32;
            i++;
        }
        else{
            listen += m[i];
        }
    }
    if(m[m.size() - 1] != '#'){
        listen += m[m.size() -1];
    }
    for(int i = 0; i < musicinfos.size(); i++){
        int time;
        string name = "", melody = "";
        time = musicinfos[i][10] - musicinfos[i][4] + 
            (musicinfos[i][9] - musicinfos[i][3]) * 10 + 
            (musicinfos[i][7] - musicinfos[i][1]) * 60 + 
            (musicinfos[i][6] - musicinfos[i][0]) * 600;
        int idx = 12;
        while(musicinfos[i][idx] != ','){
            name += musicinfos[i][idx];
            idx++;
        }
        idx++;
        for(int j = idx; j < musicinfos[i].size()-1; j++){
            if(musicinfos[i][j+1] == '#'){
                melody += musicinfos[i][j] + 32;
                j++;
            }
            else{
                melody += musicinfos[i][j];
            }
        }
        if(musicinfos[i][musicinfos[i].size()-1] != '#'){
            melody += musicinfos[i][musicinfos[i].size()-1];
        }
        // ====================저장 부분====================
        string temp= "";
        int cnt = 0;
        idx = 0;
        while(cnt != time){
            if(melody[(idx + 1) % melody.size()] == '#'){
                temp += melody[idx % melody.size()] + 32;
                idx++;
            }
            else{
                temp += melody[idx % melody.size()];
            }
            idx++;
            cnt++;
        }
        
        if(temp.size() < listen.size()) continue;
        for(int j = 0; j < temp.size(); j++){
            bool flag = true;
            for(int k = 0; k < listen.size(); k++){
                if(j + k < temp.size()){
                    if(temp[j + k] != listen[k]){
                        flag = false;
                        break;
                    }
                }else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(ans_time < time){
                    ans_time = time;
                    answer = name;
                    break;
                }
            }
        }
    }
    return answer;
}
