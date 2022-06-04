#include <string>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0;
    int correct = 0;

    FOR(i,0,lottos.size()){
        FOR(j,0,win_nums.size()){
            if(lottos[i] == win_nums[j]) correct++;
        }
        if(lottos[i] == 0) cnt++;
    }

    answer.push_back(min(6, 7-(correct+cnt)));
    answer.push_back(min(6, 7-(correct)));

    return answer;
}