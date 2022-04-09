#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define OK() cout << "OK\n"

using namespace std;

int N, M;
int nums[51];
int loca[51];

int main(void){
    cin >> N >> M;
    FOR(i,1,N+1){
        nums[i] = i;
    }

    FOR(i,1,M+1){
        cin >> loca[i];
    }

    int front = 1;
    int cnt = 0;
    bool flag = false; // false가 2번

    for(int j = 1; j<M+1; j++){
        int cnt2 = 0;
        int cnt3 = 0;
        while(nums[front] == 0) {
            front ++;
            if(front>N) front -= N;
        }
        if(nums[front] != loca[j]) {
            FOR(i,1,N+1){
                int idx = (front+i);
                if(idx > N) idx -= N;
                if(nums[idx] != 0) cnt2++;
                if(nums[idx] == loca[j]) break;
            }
            FOR(i,1,N+1){
                int idx = front - i;
                if(idx < 1) idx += N;
                // cout << "nums[" << idx << "]: " << nums[idx] <<"\n";
                if(nums[idx] != 0){
                    // cout << "nums[" << idx << "]: " << nums[idx] <<"\n";
                    cnt3++;
                }
                if(nums[idx] == loca[j]) break;
            } 
        }
        
        // cout << "cnt2: " << cnt2 << " cnt3: " << cnt3 << "\n";


        if(cnt2 > cnt3) cnt += cnt3;
        else cnt += cnt2;
        FOR(i,1,N+1){
            if(nums[i] == loca[j]){
                nums[i] = 0;
                front = i+1;
            }
        }
        // cout << "j : " << j << ", cnt : " << cnt << "\n";
        flag = false;
    }

    cout << cnt;



    return 0;
}

//어줍잖게 배열로 풀려다가 망한 케이스(테스트 케이스 다 통과하는데 틀렸습니다 나옴.)
//그냥 standard library 의 deque를 쓰자... 구현하는데 시간도 오래 걸리고 답도 마땅치 않음 ㅋㅋ
//deque << 앞뒤로 넣거나 뺄 수 있음. 그냥 스택, 큐 문제는 이거 선언해서 풀면 될 듯! 지원하는 함수 종류도 많다!!!