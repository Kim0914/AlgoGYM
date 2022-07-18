#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long number: numbers){
        long long b = 1;
        if(number%2 == 0) answer.push_back(number+1);
        else{
            while(number&b) b=b<<1;
            b=b>>1;
            answer.push_back(number+b);
        }
    }
    return answer;
}