#include <iostream>
#include <string>
using namespace std;

string src = "", dest = "";
int main() {
    cin >> src >> dest;
    
    int answer = 0;
    for (int i = 0; i < dest.size();) {
        int dest_ptr = 0;

        for (int j = 0; j < src.size(); j++) {
            int forward_cnt = 0;
            
            while (src[j + forward_cnt] == dest[i + forward_cnt])
                forward_cnt++;

            dest_ptr = max(forward_cnt, dest_ptr);
        }

        i += dest_ptr;
        answer++;
    }

    cout << answer;
    return 0;
}
