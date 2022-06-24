#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    vector<int> nums;
    int answer = 0;

    sort(numbers.begin(),numbers.end());
    do{
        for(int i=1;i<=numbers.size();i++){
            nums.push_back(stoi(numbers.substr(0,i)));
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for(int num: nums){
        if(isPrime(num)) answer++;
    }
    
    return answer;
}