#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int range = 2 * w + 1;
    int start = 1;
    for(int i = 0; i < stations.size(); i++){
        int temp_start = stations[i] - w;
        if(temp_start <= start){
            start = stations[i] + w + 1;       
            continue;
        }
        answer += (temp_start - start) / range;
        if((temp_start - start) % range != 0) answer++;
        start = stations[i] + w + 1;
    }
    if(start - 1 < n){
        answer += (n + 1 - start) / range;
        if((n + 1 - start) % range != 0) answer++;        

    }

    return answer;
}
