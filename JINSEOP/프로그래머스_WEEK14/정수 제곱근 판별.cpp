#include <string>
#include <vector>
#include <cmath>
using namespace std;
long long classify(long long n){
    double d_square_root = sqrt(n);
    long long l_square_root = sqrt(n);
    
    if(d_square_root - l_square_root == 0)
        return (l_square_root + 1) * (l_square_root + 1);
    else return -1;
}

long long solution(long long n) {
    long long answer = 0;
    
    answer = classify(n);
    return answer;
}
