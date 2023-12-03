#include <iostream>
using namespace std;
#define MAX 257

int row = 0, col = 0, blocks = 0, min_height = MAX, answer = 999999999, max_height = 0;
int minecraft_map[500][500];

int main() {
    cin >> row >> col >> blocks;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            cin >> minecraft_map[i][j];
            min_height = min(min_height, minecraft_map[i][j]);
        }

     // 어차피 256 밖에 안되니 모두 탐색해본다.
     for (int i = 0; i <= 256; i++) {
         int pile = 0;
         int dig = 0;
         int inven = blocks;
         int partial_answer = 0;

         for (int j = 0; j < row; j++) {
             for (int k = 0; k < col; k++) {
                 if (i - minecraft_map[j][k] > 0) {
                     // 높이의 차이가 양수면 쌓아야 함
                     pile += (i - minecraft_map[j][k]);
                     inven -= (i - minecraft_map[j][k]);
                 }
                 else {
                     // 높이의 차이가 음수면 깎아야 함
                     dig += (minecraft_map[j][k] - i);
                     inven += (minecraft_map[j][k] - i);
                     // 중요한 것은 깎으면 인벤토리에 넣을 수 있음!!
                 }
             }
         }

         if (inven < 0)
             continue;

         partial_answer += (pile + (dig * 2));
         if (answer >= partial_answer) {
         // i가 뒤로 갈수록 커지므로, 등호가 필요함
             answer = partial_answer;
             max_height = i;
         }
     }

    cout << answer << " " << max_height;
    return 0;
}
