#include <iostream>

#define FOR(i,a,b) for(int i =a;i<b;i++)

using namespace std;

int N;
int nums[129][129];
int store[2];


int dc(int size, int x, int y, int color){
    if(size == 1) {
        if(nums[x][y] == color) return 1;
        else return 0;
    }

    int cnt = 0;
    FOR(i,0,2){
        FOR(j,0,2){
            cnt += dc(size/2, i*size/2+x, j*size/2+y, color);   
        }
    }

    if(cnt == size*size) cnt = 1;
    // cout << "[" << size << ", " << x << ", " << y << ", " << color << "] cnt: " << cnt << "\n"; 
    return cnt;
}

int main(void){
    cin >> N;

    FOR(i,1,N+1){
        FOR(j,1,N+1){
            cin >> nums[i][j];
        }
    }


    cout << dc(N, 1, 1, 0) << "\n";
    cout << dc(N, 1, 1, 1) << "\n";

    return 0;
}

// dp로 풀다가 막혀서 선회함.. dp로 풀 수 있긴한데 직관적이지 않은 듯.
// 깔끔하지 않는 코드를 지양하다보니까 문제 풀이 시간이 늘어나는 것 같다.

// 직관이 좋은 코드 vs 효율적인 코드 << 뭘 선택해야 할까?
// 일단 둘 다 신경 쓰면서 짜고 있긴한데, 이게 알고리즘 테스트를 준비하는 자세가 맞나?
// 다음부터는 일단 통과하는 것에 초점을 두고 맞추고 나서 리펙토링하는 시간을 갖거나, 다른 코드를 보면서 수정 보완해야겠다.