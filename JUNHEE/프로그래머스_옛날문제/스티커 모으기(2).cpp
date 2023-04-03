#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    vector<int> dp_first(sticker.size());
    dp_first[0] = sticker[0];
    dp_first[1] = dp_first[0];
    for(int i = 2; i < sticker.size() - 1; i++){
        dp_first[i] = max(dp_first[i-1], dp_first[i-2] + sticker[i]);
    }
    vector<int> dp_second(sticker.size());
    dp_second[0] = 0;
    for(int i = 1; i < sticker.size(); i++){
        dp_second[i] = max(dp_second[i-1], dp_second[i-2] + sticker[i]);
    }
    answer = max(*max_element(dp_first.begin(), dp_first.end()), *max_element(dp_second.begin(), dp_second.end()));
    
    
    
    return answer;
}
