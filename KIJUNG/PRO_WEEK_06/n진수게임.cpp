#include <string>
#include <math.h>

using namespace std;

string e = "0123456789ABCDEF";

string trans(int notation,int num){
    string tmp = "";
    int p = 0;
    
    while(num>=(int)pow(notation,p)) p++;
    if(p>0) p--;

    while(p>=0){
        int q = num/(int)pow(notation, p);
        tmp+=e[q];
        num = num%(int)pow(notation, p);
        p--;
    }

    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string seq = "0";

    //진수 변환
    for(int i=1;seq.size()<m*t;i++) seq += trans(n, i);
    for(int i=0;i<t;i++) answer += seq[i*m+p-1];
    
    return answer;
}