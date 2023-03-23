#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
    자.. dfs로 푸는데, 각 칸을 먹은 경우, 안먹은 경우로 가자..
*/
vector<int> result;
int t_max = -1;

void calc(vector<int> apeach, vector<int> ryan){
    int a = 0, r = 0;
    for(int i = 0; i < 11; i++){
        if(apeach[i] < ryan[i])
            r += 10 - i;
        else if(0 < apeach[i])
            a += 10 - i;
    }
    if(r - a > 0 && t_max < (r - a)){
        cout << r << " " << a << endl;
        result = ryan;
        t_max = r - a;
    }
    else if(r - a > 0 && t_max == (r - a)){
        for(int i = 10; i >=0; i--){
            if(result[i] != 0 || ryan[i] != 0){
                if(ryan[i] > result[i])
                    result = ryan;
                else if(ryan[i] == result[i])
                    continue;
                else
                    break;
            }
        }
    }
}

void dfs(int idx, int arrow, vector<int> apeach, vector<int>ryan){
    if(idx == 11 || arrow == 0){
        if(arrow != 0){
            ryan[10] += arrow;
        }
        calc(apeach, ryan);
        return;
    }
    if(apeach[idx] < arrow){
        ryan[idx] += apeach[idx] + 1;
        arrow -= apeach[idx] + 1;
        dfs(idx + 1, arrow, apeach, ryan);
        arrow += apeach[idx] + 1;
        ryan[idx] -= apeach[idx] + 1;
    }
    dfs(idx + 1, arrow, apeach, ryan);
    
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(1, -1);
    vector<int> ryan(11,0);
    result.resize(11,0);
    dfs(0, n, info, ryan);
    for(auto i : result){
        if(i != 0){
            answer = result;
        }
    }
    return answer;
}
