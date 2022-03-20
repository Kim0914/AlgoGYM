#include <iostream>
#include <math.h>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int price[1001][3];
int N;

int main(void){
    cin >> N;

    FOR(i,1,N+1){
        cin >> price[i][0] >> price[i][1] >> price[i][2];
    }
    FOR(i,2,N+1){
        price[i][0] += min(price[i-1][1],price[i-1][2]);
        price[i][1] += min(price[i-1][0],price[i-1][2]);
        price[i][2] += min(price[i-1][1],price[i-1][0]);
    }
    cout << min(price[N][0], min(price[N][1], price[N][2]));

    return 0;
}
//DP(동적 계획법): 전채 문제(큰 문제)를 부분 문제(작은 문제)로 나누고, 각 부분 문제의 답을 계산하고 저장한 뒤 계산값을 활용하여 전체 문제를 해결하는 방식.
//              작은 문제들은 항상 같은 답이 반복된다. << 저장의 필요성
//              기억하며 풀기
//              주어진 문제의 구조가 최적 부분 구조일 때 활용하면 효율이 높다.
//              최적 부분 구조: 문제의 최적 해결 방법이 부분 문제에 대한 최적 해결 방법으로 이루어진 구조
//              즉, 동적 계획법은 최적 부분 구조(Optimal Substructure)를 지닌 중복된 하위 문제들(Overlapping Subproblems)을 분할 정복으로 풀이하는 문제해결 패러다임이다.

//방법 : Top-Down, Bottom-Up

//동적 계획법의 주요 기술: 메모이제이션(Memoization), 타뷸레이션(Tabulation)
//메모이제이션: top-down 방식에서 구해야 할 해를 얻기 위해서 계산이 필요한 순간에 값을 저장 (재귀 함수를 이용)
//타뷸레이션:   bottom-up 방식에서 하위값을 계산하여 저장한 뒤 상위 값을 구하며 구해야 할 해까지 도달 (반복문을 이용)

//특징: 그리디 알고리즘에 비해서 시간이 오래걸린다. 항상 최적의 해를 구할 수 있다.
//     메모리를 사용함으로써 시간복잡도를 현저히 개선할 수 있다.(실행시간과 메모리공간은 trade-off관계에 있기 때문)

//이 알고리즘으로 문제를 풀 때 초점: 일정 규칙에 의해 재귀함수를 방문한다면, 그 규칙(점화식)을 빠르게 찾고 효과적으로 저장하는 방식을 생각하는 것이 중요하다.
//ex: 피보나치 수열 구하기
