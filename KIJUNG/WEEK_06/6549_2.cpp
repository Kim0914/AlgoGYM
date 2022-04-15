#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N;
long long h[100002];
int tree[400001];

/**
 * @brief: 높이가 최소인 세그먼트 트리로 트리를 초기화한다
 */
int treeInit(int idx, int s, int e){
    int mid = (s+e)/2;
    if(s == e) return tree[idx] = s;

    int left = treeInit(idx*2, s, mid);
    int right = treeInit(idx*2+1, mid+1, e);

    return tree[idx] = ((h[left] > h[right])? right:left);
}

/**
 * @brief: 구간에서 측정한 최소 높이를 반환하는 함수
 * @param: startN, endN : 노드 탐색용 구간 
 * @param: start, end : 실제 최솟값을 탐색할 범위
 */
int minIdx(int idx, int startN, int endN, int start, int end){
    if(endN < start || startN > end) return 100001;
    if(start <= startN && endN <= end) return tree[idx];

    int mid = (startN+endN)/2;
    int leftIdx = minIdx(2*idx, startN, mid, start, end);
    int rightIdx = minIdx(2*idx+1, mid+1, endN, start, end);

    return (h[leftIdx]>h[rightIdx]? rightIdx:leftIdx) ;
}

/**
 * @brief: 주어진 구간에서 최소 높이에 따른 넓이, 최소 높이에 해당하는 인덱스 양 옆에서 최대 넓이 중 가장 큰 넓이.
 */
long long solve(int start, int end){
    if(start > end) return 0;
    int idx = minIdx(1, 1, N, start, end);
    return max(h[idx]*(end-start+1), max(solve(start, idx-1), solve(idx+1, end)));
}

int main(void){
    h[100001] = 1000000001; // 최대 넓이보다 넓게 설정 >> 범위에서 제외시켜줌
    while(1){
        cin >> N;
        if(N==0) break;
        FOR(i,1,N+1){
            cin >> h[i];
        }
        treeInit(1, 1, N);
        cout << solve(1,N) << "\n";
    }

    return 0;
}
// 세그먼트 트리를 이용해서 푸는 문제
// 세그먼트 트리는 구간을 탐색하는 문제를 풀때 쓰면 좋다!
// 세그먼트 트리: https://m.blog.naver.com/ndb796/221282210534
// 6549풀이: https://cocoon1787.tistory.com/314