#include <iostream>
#include <unordered_map>
using namespace std;

int num = 0, room_state = 1, answer = 0;
char game_kind = 'X';
string name = "";
unordered_map<string, bool> duplication_validator;
int main() {
    cin >> num >> game_kind;
    for (int i = 0; i < num; i++) {
        cin >> name;

        if (duplication_validator[name])
            continue;

        duplication_validator[name] = true;
        room_state++;

        // 게임 진행을 못했으면?
        // duplication validator에서 빼야한다.
        switch (game_kind)
        {
        case 'Y':
            if (room_state == 2) {
                room_state = 1;
                answer++;
            }
        // 1명 입장 가능
            break;
        case 'F':
            if (room_state == 3) {
                room_state = 1;
                answer++;
            }
        // 2명 입장 가능
            break;
        case 'O':
        // 3명 입장 가능
            if (room_state == 4) {
                room_state = 1;
                answer++;
            }
            break;
        }
    }

    cout << answer;
    return 0;
}
