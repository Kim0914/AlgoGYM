#include <string>
#include <vector>
#include <iostream>
using namespace std;

int min_dart_count = 987654321, max_single_bool = 0;
void play_dart(int score, int dart_count, int single_bool) {
    if (score < 0)
        return; // 버스트
    if (dart_count > min_dart_count)
        return; // 넘어가면 탐색할 필요 없음

    if (score == 0) {
        if (min_dart_count >= dart_count) {
            if (min_dart_count == dart_count) {
                max_single_bool = max(single_bool, max_single_bool);
                return; // 같은 경우엔 더 싱글/불이 더 큰 경우로
            }

            min_dart_count = dart_count;
            max_single_bool = single_bool;
            // 다른 경우에는 그럼 싱글/불도 초기화 해야함
        }

        return;
    }

    play_dart(score - 50, dart_count + 1, single_bool + 1); // 불
    for (int i = 20; i >= 1; i--) {
        play_dart(score - i, dart_count + 1, single_bool + 1); // 싱글
        play_dart(score - (i * 2), dart_count + 1, single_bool); // 더블
        play_dart(score - (i * 3), dart_count + 1, single_bool); // 트리플
    }
}

vector<int> solution(int target) {
    vector<int> answer;

    play_dart(target, 0, 0);
    answer.push_back(min_dart_count);
    answer.push_back(max_single_bool);

    return answer;
}
