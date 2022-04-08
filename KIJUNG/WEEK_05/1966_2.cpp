#include <iostream>

using namespace std;

int N, M, idx;
int docu[100];

int main(void){
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> M >> idx;
        int cnt =0;
        int max =0;
        int front = 0;
        for(int j=0;j<M;j++){
            cin >> docu[j];
        }

        while(1){
            for(int j=0;j<M;j++){
                if(max < docu[j]) max = docu[j];
            }
            while(max != docu[front]) front = (front+1)%M;
            cnt++;
            if(front == idx) break;
            docu[front] = 0;
            max = 0;
        }
        cout << cnt << "\n";
    }

    return 0;
}

//배열을 가지고 인덱스 나머지 연산으로 !q.empty()처럼 계속 큐를 돌릴 수 있다!