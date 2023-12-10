#include <iostream>
#include <string>
using namespace std;

int tc = 0;
string src1 = "", src2 = "", target = "";
int main() {
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> src1 >> src2 >> target;

        int src1_ptr = 0, src2_ptr = 0;
        for (int target_ptr = 0; target_ptr < target.size(); target_ptr++) {
            if (target[target_ptr] == src1[src1_ptr] && target[target_ptr] == src2[src2_ptr]) {
                // 동시에 맞는 알파벳이 있으면?
                if (src1_ptr > src2_ptr)
                    src2_ptr++;
                else
                    src1_ptr++;
                // 진행률이 더 낮은 포인터를 뒤로 미뤄보자

                continue; // 다음 과정으로
            }

            if (target[target_ptr] == src1[src1_ptr])
                src1_ptr++;
            else if (target[target_ptr] == src2[src2_ptr])
                src2_ptr++;
        }

        if(src1_ptr == src1.size() && src2_ptr == src2.size())
            cout << "Data set " << (i + 1) << ": yes";
        else
            cout << "Data set " << (i + 1) << ": no";
    }

    return 0;
}
