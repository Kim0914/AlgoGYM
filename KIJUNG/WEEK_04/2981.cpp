#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
int nums[101];
int diff[100];
int g;
vector<int> yak;

int gcd(int a, int b){
    int c;
    while(b != 0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main(void){
    cin >> N;

    FOR(i,1,N+1){
        cin >> nums[i];
    }

    sort(nums+1, nums+N+1);

    FOR(i,2,N+1){
        diff[i-1] = nums[i] - nums[i-1];
    }

    g = diff[1];

    FOR(i,2,N+1){
        g = gcd(g, diff[i]);
    }

    for(int i = 1;i<= sqrt(g); i++){
        if(g%i == 0){
            yak.push_back(i);
            yak.push_back(g/i);
            if(g == i*i) yak.pop_back();
        }
    }

    sort(yak.begin(), yak.end());

    FOR(j,1,yak.size()){
        cout << yak[j] << " ";
    }

    return 0;
}

// 나머지가 같다는 정보를 통해 점화식을 찾자! 정렬!