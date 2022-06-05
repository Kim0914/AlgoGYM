#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MAX_NUM 10000000000000;

using namespace std;

long long judgeNum(long long n, &vector<int> times){
    long long num = 0;
    FOR(i,0,times.size()){
        num += n/((long long)times[i]);
    }
    return num;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long start = 0;
    long long end = MAX_NUM;

    while(start<end){
        long long mid = (start+end)/2;
        if(judgeNum(mid, times)>=n){
            end = mid;
        }
        else {
            start = mid+1;
        }
    }
    cout << start;
    answer = start;
    
    return answer;
}