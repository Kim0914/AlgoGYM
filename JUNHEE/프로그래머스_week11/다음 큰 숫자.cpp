#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    bool flag = true;
    int next = n + 1;
    int count = 0;
    while(n){
        if(n % 2 == 1) count++;
        n /= 2;
    }
    while(flag){
        int t_next = next, t_count = 0;
        while(t_next){
            if(t_next % 2 == 1) t_count++;
            t_next /= 2;
        }
        if(t_count == count) flag = false;
        else next++;
    }
    return next;
}
