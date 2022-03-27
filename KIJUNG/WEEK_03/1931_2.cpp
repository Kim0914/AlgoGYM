#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i = a; i<b; i++)

using namespace std;

int N;
pair<int, int> con[100001];

int main(void){
    cin >> N;

    FOR(i,0,N){
        cin >> con[i].second >> con[i].first;
    }
    sort(con, con+N);

    int cnt=0;
    int time = 0;

    FOR(i,0,N){
        if(time>con[i].second) continue;
        cnt++;
        time = con[i].first;
    }
    cout << cnt;

    return 0;
}
// 종료시간으로 sort하면 시작시간 조건만 검사하면 최적의 해가 나온다.

//그리디 알고리즘(Greedy Algorithm)
// 현재 주어진 상황에서 최선의 선택을 하는 것
// 항상 최적의 해를 만족시키지 않는다.
// 조건 1: 탐욕스런 선택 조건(greedy choice property) << 앞의 선택이 이후의 선택에 영향을 주지 않아야 함. 영향을 생각하지 않고, 현재 상황에서 최선의 선택!
// 조건 2: 최적 부분 구조 조건(optimal substructure) << 전 코멘트에서 설명했으므로 생략.

// 어떨때 사용해야 하는가?
// 그리디 알고리즘을 사용했을 때 문제조건을 만족하는지 여부를 파악하고, 충분히 문제조건을 만족하는 해가 도출될 때 그리디 알고리즘을 사용한다.