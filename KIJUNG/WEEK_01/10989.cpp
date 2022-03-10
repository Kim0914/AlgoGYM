#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i = a; i<b; i++) 

using namespace std;

int N;
int tmp;
int nums[10001] = {0,};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    FOR(i,0,N){
        cin >> tmp;
        nums[tmp]++;
    }

    FOR(i,0,10001){
        FOR(j,0,nums[i]){
            cout << i << "\n";
        }        
    }

    return 0;
}

//범위가 작은 sort는 갯수를 배열사이즈로 설정하여 sort를 구현할 수 있다. 
//중복이 없다면 시간복잡도는 n이므로 STL의 sort알고리즘의 시간 복잡도인 nlogn보다 더빠르다.
//ios::sync_with_stdio(false); << 이 코드는 iostream과 c 라이브러리의 stdio의 버퍼 동기화를 막아준다. c++만의 독립적인 버퍼만 사용한다. 따라서 더욱 빠른 실행이 가능!
//간혹 런타임 에러를 발생시키는 경우가 있으니, 런타임에러가 발생한다면 stdio.h을 include하고 scanf("%d", &a)와 printf("%d\n",a)을 사용하자.