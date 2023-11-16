#include <iostream>
using namespace std;

int fee[3], parking_lot[101], in_time = 0, out_time = 0, min_in = 99999, max_out = 0, answer = 0;
void check_min_max() {
    if (in_time < min_in)
        min_in = in_time;
    if (out_time > max_out)
        max_out = out_time;
}

int main() {
    for (int i = 0; i < 3; i++)
        cin >> fee[i];
    
    for (int i = 0; i < 3; i++) {
        cin >> in_time >> out_time;
        
        check_min_max();
        for (int j = in_time; j < out_time; j++)
            parking_lot[j] += 1;
    }

    for (int i = min_in; i <= max_out; i++)
        answer += (fee[parking_lot[i] - 1]) * parking_lot[i] ;
    cout << answer;

    return 0;
}
