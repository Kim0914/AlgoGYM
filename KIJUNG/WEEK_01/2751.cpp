#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i = a; i<b; i++) 

using namespace std;

int N, tmp;
vector<int> nums;

bool asc(int i, int j){return i<j;}

int main(void){
    cin >> N;

    FOR(i,0,N){
        cin >> tmp;
        nums.push_back(tmp);
    }

    sort(nums.begin(), nums.end(), asc);

    FOR(i,0,N){
        cout << nums[i] << "\n";
    }

    return 0;
}

//endl은 버퍼를 비워주는 행위가 포함되어 있기 때문에 '\n'보다 시간이 더 걸린다.
//따라서 앞으로는 endl대신 \n을 사용하자.