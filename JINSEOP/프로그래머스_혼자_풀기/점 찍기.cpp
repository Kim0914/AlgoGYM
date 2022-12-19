#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

long long substitute(int k, int d) {
   long long res = 0;

   for (int i = 0; i <= d; i += k) {
       long long y = sqrt((d*d) - (i*i));
       res += floor(y / k) + 1;
   }

   return res;
}

long long solution(int k, int d) {
    long long answer = 0;
    
    answer = substitute(k, d);
    return answer;
}

int main() {
    cout << solution(2, 4);
}

// 이 코드는 왜 안되는가?
