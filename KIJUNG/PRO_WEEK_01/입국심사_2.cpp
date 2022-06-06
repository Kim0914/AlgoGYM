#include <vector>

#define MAX_NUM 10000000000000; 

using namespace std;

long long solution(int n, vector<int> times) {
    long long start = 0;
    long long end = MAX_NUM;
    
    while(start<end){
        long long mid = (start+end)/2;
        long long judgeNum = 0;

        for(int time: times) judgeNum += mid/time; 
        
        if(judgeNum >= n) end = mid;
        else start = mid+1;
    }
    
    return start;
}

// 최대 경우의 수: 1000000000/100000 * 1000000000 >> 10조
// range-base loop 자주써야겠다. 편하네.