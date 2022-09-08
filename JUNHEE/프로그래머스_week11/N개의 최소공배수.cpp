#include <string>
#include <vector>

using namespace std;
int GCD(int a, int b){
    int temp;
    if(a < b){
        temp = a;
        a = b;
        b = temp;
    }
    temp = 0;
    while(b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i = 0; i < arr.size(); i++){
        int t_gcd = GCD(answer, arr[i]);
        int t_lcm = answer * arr[i] / t_gcd;
        answer = t_lcm;
    }
    return answer;
}
