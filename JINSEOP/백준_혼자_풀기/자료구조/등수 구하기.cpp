#include <iostream>
#include <queue>
using namespace std;

int num = 0, new_score = 0, limit = 0, score = 0, answer = 1;
int min_score = 2100000000;
priority_queue<int> score_board;
int main() {
    cin >> num >> new_score >> limit;
    for (int i = 0; i < num; i++) {
        cin >> score;
        min_score = min(min_score, score);
        score_board.push(score);
    }

    // 우선순위 큐를 통해 O(logN) 정렬
    // 이후 태수의 점수를 삽입
    if (num == limit) {
    // 꽉 찼는데 최소 점수보다 낮거나 같으면 어차피 못넣음
        if (min_score >= new_score)
            cout << -1;
        else {
            score_board.push(new_score);
            int limit_for_sub = limit;
            while (!score_board.empty() && limit_for_sub--) {
                // 큐가 비거나, 제한 갯수까지 pop을 한다.
                if (score_board.top() == new_score)
                    break;

                score_board.pop();
                answer++;
            }

            if (answer > limit)
                cout << -1;
            else
                cout << answer;
        }
    }
    else {
        score_board.push(new_score);
        int limit_for_sub = limit;
        while (!score_board.empty() && limit_for_sub--) {
            // 큐가 비거나, 제한 갯수까지 pop을 한다.
            if (score_board.top() == new_score)
                break;

            score_board.pop();
            answer++;
        }

        if (answer > limit)
            cout << -1;
        else
            cout << answer;
    }

    return 0;
}
