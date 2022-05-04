#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, sum, cnt;
bool nums[4000001];
vector<int> prime;

int main(void){
    cin >> N;
    nums[1] = true;

    FOR(i,2,2001){
        for(int j=2;i*j<=4000000;j++){
            nums[i*j] = true;
        }
    }

    FOR(i,1,4000001){
        if(!nums[i]) prime.push_back(i);
    }

    int point1=0;
    int point2=0;
    sum = prime[0];

    while(point1<prime.size() && point2<prime.size()){
        if(sum<N) sum += prime[++point2];
        else{
            if(sum == N) cnt++;
            sum -= prime[point1++];
        }
    }

    cout << cnt;

    return 0;
}