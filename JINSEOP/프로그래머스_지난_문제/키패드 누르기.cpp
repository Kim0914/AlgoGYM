#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, char> which_hand;
string res = "";
void init_map() {
    which_hand[1] = 'L'; which_hand[4] = 'L'; which_hand[7] = 'L';
    which_hand[3] = 'R'; which_hand[6] = 'R'; which_hand[9] = 'R';
    which_hand[2] = 'N'; which_hand[5] = 'N'; which_hand[8] = 'N'; which_hand[11] = 'N';
}

void move_finger(vector<int> numbers, string hand) {
    int curr_left = 10, curr_right = 12;

    for (int num : numbers) {
        if (num == 0)
            num = 11;

        if (which_hand[num] == 'L')
            curr_left = num;
        if (which_hand[num] == 'R')
            curr_right = num;
        if (which_hand[num] == 'N') {
            int diff_l = abs(curr_left - num);
            int diff_r = abs(curr_right - num);

            int dist_l = (diff_l / 3) + (diff_l % 3);
            int dist_r = (diff_r / 3) + (diff_r % 3);

            if (dist_l < dist_r) {
                curr_left = num;
                res += 'L';
            }
            if (dist_l > dist_r) {
                curr_right = num;
                res += 'R';
            }
            if (dist_l == dist_r) {
                if (hand == "left") {
                    curr_left = num;
                    res += 'L';
                }
                else {
                    curr_right = num;
                    res += 'R';
                }
            }

            continue;
        }
        
        res += which_hand[num];
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    init_map();
    move_finger(numbers, hand);

    answer = res;
    return answer;
}
