#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int N, tmp;
int nums[8001] = {0,};
int result[4] = {0,};
int cnt = 0;
int M = -1;
int m = 8001;

int main(void){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    FOR(i,0,N){
        cin >> tmp;
        nums[tmp+4000]++;
        result[0] += tmp;
    }

    result[0] = ((result[0] > 0)? (int)((float)result[0]/N + 0.5):(int)((float)result[0]/N - 0.5)); // 반올림 구현

    FOR(i,0,8001){
        cnt += nums[i];
        if(cnt >= N/2+1){
            result[1] = i;
            break;
        }
    }

    tmp = *max_element(nums, nums + 8001);
    int check = 0; 

    FOR(i,0,8001){
        if(nums[i]>0){
            if(M<i) M=i;
            if(m>i) m=i;
        }
        if(nums[i] == tmp && check < 2){
            result[2] = i;
            check++;
        }
    }
    result[3] = M-m;

    cout << result[0] << "\n";
    cout << result[1]-4000 << "\n";
    cout << result[2]-4000 << "\n";
    cout << result[3] << "\n";

    return 0;
}
// 시간 복잡도가 3n인 알고리즘