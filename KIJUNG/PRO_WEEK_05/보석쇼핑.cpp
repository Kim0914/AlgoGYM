#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> uniqGems;

    for(string gem: gems){
        uniqGems[gem] = 0;
    }

    int start=0;
    int end=gems.size()-1;
    int cnt = 0;

    for(int i=0;i<gems.size();i++){
        if(uniqGems[gems[i]] == 0) {
            cnt++;
        }
        uniqGems[gems[i]]++;
        if(cnt == uniqGems.size()){
            end = i;
            uniqGems[gems[i]]--;
            break;
        }
    }

    answer.push_back(start+1);
    answer.push_back(end+1);

    for(int i=end;i<gems.size();i++){
        uniqGems[gems[i]]++;
        end = i;
        for(int j=start; j<end; j++){
            if(uniqGems[gems[j]]<2) {
                start = j;
                break;
            }
            uniqGems[gems[j]]--;
        }
        if(end-start < answer[1]-answer[0]){
            answer[1] = end+1;
            answer[0] = start+1;
        }
    }

    return answer;
}