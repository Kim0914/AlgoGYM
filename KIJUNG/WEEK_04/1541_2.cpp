#include <iostream>

using namespace std;

bool f = false;
int m, num;
char op;

int main(void){
    scanf("%d", &m);

    while(scanf("%c%d", &op, &num)==2){
        if(op == '-') f = true;
        if(f) m -= num;
        else m += num;
    }

    printf("%d",m);
    return 0;
}