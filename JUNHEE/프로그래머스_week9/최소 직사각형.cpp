#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxlen = 0, minlen = 0;
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i][0] < sizes[i][1]){
            if(minlen < sizes[i][0]) minlen = sizes[i][0];
            if(maxlen < sizes[i][1]) maxlen = sizes[i][1];
        }
        else{
            if(minlen < sizes[i][1]) minlen = sizes[i][1];
            if(maxlen < sizes[i][0]) maxlen = sizes[i][0];
        }
    }
    answer = maxlen * minlen;
    return answer;
}
