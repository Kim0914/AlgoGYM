#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, W;
int incidence[1001][1001];
vector<pair<int, int> > pathP1;
vector<pair<int, int> > pathP2;

int minDistance(int p1, int p2){
    if(p1 == W || p2 == W) return 0;
    if(incidence[p1][p2] != -1) return incidence[p1][p2];

    int next = max(p1,p2) + 1;
    int distP1 = abs(pathP1[p1].first - pathP1[next].first) + abs(pathP1[p1].second - pathP1[next].second);
    int distP2 = abs(pathP2[p2].first - pathP2[next].first) + abs(pathP2[p2].second - pathP2[next].second);

    int result1 = distP1 + minDistance(next, p2);
    int result2 = distP2 + minDistance(p1, next);

    return incidence[p1][p2] = min(result1, result2);
}

void route(int p1, int p2){
    if(p1 == W || p2 == W) return;

    int next = max(p1,p2) + 1;
    int distP1 = abs(pathP1[p1].first - pathP1[next].first) + abs(pathP1[p1].second - pathP1[next].second);
    int distP2 = abs(pathP2[p2].first - pathP2[next].first) + abs(pathP2[p2].second - pathP2[next].second);

    int result1 = distP1 + incidence[next][p2];
    int result2 = distP2 + incidence[p1][next];

    if(result1 > result2){
        cout << 2 << "\n";
        route(p1,next);
    }
    else{
        cout << 1 << "\n";
        route(next,p2);
    }
}

int main(void){
    cin >> N >> W;

    memset(incidence, -1, sizeof(incidence));
    
    pathP1.push_back(make_pair(1,1));
    pathP2.push_back(make_pair(N,N));

    FOR(i,0,W){
        int y, x;
        cin >> y >> x;
        pathP1.push_back(make_pair(y,x));
        pathP2.push_back(make_pair(y,x));
    }

    cout << minDistance(0,0) << "\n";
    route(0,0);

    return 0;
}

/**
 * @brief: 풀이 핵심
 dp 인덱스를 경찰차1,2의 마지막 위치라고 본다.
 dp값: 현재 경찰차 1,2에서 나머지를 앞으로 가야할 거리의 최솟값.
 따라서 dp[0][0]이 최종 구하는 값이 된다.
 재귀 함수를 통해 다음 위치를 경찰차1이 갔을 경우와 경찰차2가 갔을 경우중 최솟값을 선택한다.

 이 문제가 어려운 이유
 브루트 포스 알고리즘으로 보면 O(n^2)이라서 중복되는 연산을 어떻게 처리할지 감이 안잡힌다.
 만약 경찰차의 최종 위치를 dp인덱스로 해야한다는 사실을 안다해서
 값을 어떻게 활용해하는지 생각하기가 어렵다.
 이 문제에서는 이때까지 온 최솟값이 아닌, 경찰차 위치가 정해져 있을 때 앞으로의 최솟값을 저장하는 방식이기 때문이다.
 한마디로 거꾸로 채워나가는 방식!
 * 
 */

/**
 * @brief: 이차원 배열 특정값 할당
int temp[row][col];

특정값이 0인 경우
 > 전역변수로 할당

특정값이 -1 인 경우
> memset(temp, -1, sizeof(temp));

그 외 다른 특정값인 경우
fill함수 사용
fill함수의 첫번째 인자와 두번째 인자는 [처음 주소값, 마지막 주소값)을 의미한다.
세번째 인자는 특정값.
> fill(temp[0], temp[row], 999);
> fill(&temp[0][0], &temp[row-1][col], 999); 
 * 
 */
