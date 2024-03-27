#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a_dice_vec;
vector<int> b_dice_vec;
vector<int> a_sum_vec;
vector<int> b_sum_vec;
vector<int> answer_vec;
bool dice_info[10];
int max_win_cnt = 0;
void select_each_digit(int a_sum, int b_sum, int depth, int size, vector<vector<int>>& dice) {
    if (depth == size) {
        a_sum_vec.push_back(a_sum);
        b_sum_vec.push_back(b_sum);
        return;
    }

    for (int i = 0; i < 6; i++)
        select_each_digit(a_sum + dice[a_dice_vec[depth]][i], b_sum + dice[b_dice_vec[depth]][i], depth + 1, size, dice);
}

void calculate_sum(vector<vector<int>> &dice) {
    int size = a_dice_vec.size();
    for (int i = 0; i < 6; i++)
        select_each_digit(dice[a_dice_vec[0]][i], dice[b_dice_vec[0]][i], 1, size, dice);

    int a_size = a_sum_vec.size();
    int b_size = b_sum_vec.size();
    sort(a_sum_vec.begin(), a_sum_vec.end());
    sort(b_sum_vec.begin(), b_sum_vec.end());

    int a_win_cnt = 0, a_ptr = 0, b_ptr = 0;
    while (a_ptr < a_size && b_ptr < b_size) {
        if (a_sum_vec[a_ptr] > b_sum_vec[b_ptr])
                b_ptr++;
        else {
            a_win_cnt += b_ptr;
            a_ptr++;
        }
    }

    if (b_ptr == b_size)
    // B의 합 탐색이 먼저 끝난 경우
        a_win_cnt += (b_ptr * (a_size - a_ptr));
    // 어차피, A가 B의 길이 만큼 다 이기는 조합 밖에 안남음
    // 그냥 A의 남은 수 * B의 길이 만큼 더해주면 됨

    if (a_win_cnt > max_win_cnt) {
        answer_vec = a_dice_vec;
        max_win_cnt = a_win_cnt;
    }
}

void make_b_vec() {
    for (int i = 0; i < 10; i++)
        if (!dice_info[i])
            b_dice_vec.push_back(i);
}

void select_dice(int depth, int idx, int size, vector<vector<int>> &dice) {
    if (depth == size / 2) {
        // 여기서 비교 계산
        make_b_vec();
        calculate_sum(dice);

        a_sum_vec.clear();
        b_sum_vec.clear();
        b_dice_vec.clear();
        return;
    }

    for (int i = idx + 1; i < size; i++) {
        a_dice_vec.push_back(i);
        dice_info[i] = true;
        select_dice(depth + 1, i, size, dice);
        a_dice_vec.pop_back();
        dice_info[i] = false;
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    int size = dice.size();
    for (int i = 0; i < size; i++) {
        a_dice_vec.push_back(i);
        dice_info[i] = true;
        select_dice(1, i, size, dice);
        a_dice_vec.pop_back();
        dice_info[i] = false;
    }

    for (auto i : answer_vec)
        answer.push_back(i + 1);
    return answer;
}
