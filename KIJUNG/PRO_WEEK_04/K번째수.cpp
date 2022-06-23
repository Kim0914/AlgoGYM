#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(vector<int> command: commands){
        vector<int> tmp;
        tmp.resize(command[1]-command[0]+1);
        copy(array.begin()+command[0]-1,array.begin()+command[1],tmp.begin());
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[command[2]-1]);
    }
    
    return answer;
}