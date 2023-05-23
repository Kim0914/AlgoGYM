#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n = 0, tape_len = 0, coord = 0, cnt = 0;
    priority_queue<int, vector<int>, greater<>> pipe;

    cin >> n >> tape_len;
    for (int i = 0; i < n; i++) {
        cin >> coord;
        pipe.push(coord);
    }

    while (!pipe.empty()) {
        cnt++;

        int start = pipe.top();

        for (int i = 0; i < tape_len; i++) { 
            int curr = pipe.top();

            if (curr - start >= tape_len)
                break;

            pipe.pop();
           
            if (pipe.empty())
                break;
        }
    }

    cout << cnt;

    return 0;
}
