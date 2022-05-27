#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int n,k,low,high,ans;

int main(void){
    cin >> n >> k;

    low=1;
    high=k;

    while(low<=high){
        int mid = (low+high)/2;
        int cnt = 0;

        FOR(i,1,n+1){
            cnt += min(mid/i, n);
        }

        if(cnt<k) low = mid+1;
        else{
            ans = mid;
            high = mid-1;
        }
    }
    
    cout << ans;

    return 0;
}
// 이분 탐색 접근이 어려웠던 문제
// 이차원 배열 인덱스의 곱을 이분탐색하는 방법이면 곱해서 나오는 수를 가지고 이분탐색을 해야하는데
// 100억이나 되는 수를 이분탐색하면서 같거나 작은 수를 세면서 답이 될 수 있는 값을 찾으면
// 그 값이 바로, 곱해서 나오는 수라는 생각이 쉽게 안든다.