#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int tmp = x;
    int t_x = 0;
    while(tmp != 0){
        t_x += tmp % 10;
        tmp /= 10;
    }
    if(x % t_x == 0) return true;
    else return false;
}
