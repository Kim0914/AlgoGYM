#include <iostream>
using namespace std;
#define ll long long

ll home_x = 0, home_y = 0, one_block = 0, diagonal = 0, answer = 0;
void optimize() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    optimize();
    cin >> home_x >> home_y >> one_block >> diagonal;

    // 가로 + 세로 (Manhattan distance)가 더 짧으면 그렇게 간다.
    // 대각선 (Euclidean distance)이 더 짧으면 그렇게 간다.

    if ((one_block * 2) <= diagonal)
        answer = (home_x + home_y) * one_block;
    else {
        // 여기서 문제는, 대각선만으로 갈 수 있는 위치인가?
        // 그것에 대한 판단은, x + y = 짝수인가?
        // 합이 짝수이면 모두 가능.

       ll diagonal_std = min(home_x, home_y);
       answer = diagonal_std * diagonal;
       // 최대한 가까이 대각선으로 감.
       // 이제 직선으로 갈 지 대각선으로 갈지 판단한다.

       ll straight_std = abs(home_x - home_y);
       ll straight_to_cmp =  straight_std * one_block;
       ll diagonal_to_cmp = 0;
       if (straight_std % 2 == 0)
           diagonal_to_cmp = straight_std * diagonal;
       else
           diagonal_to_cmp = (straight_std - 1) * diagonal + one_block;

       answer += min(straight_to_cmp, diagonal_to_cmp);
    }

    cout << answer;
    return 0;
}
