#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M, parent[201] ;

void possible(){
    int tmp, tp;
    cin >> tmp;
    tp = parent[tmp];

    FOR(i,1,M){
        cin >> tmp;
        if(tp != parent[tmp]){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int set_find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = set_find(parent[x]);
}

void set_union(int x, int y){
    int px = set_find(x);
    int py = set_find(y);

    if(px<py) parent[py] = px;
    else parent[px] = py;
}

int main(void){
    cin >> N >> M;
    FOR(i,1,N+1){
        parent[i] = i;
    }

    FOR(i,1,N+1){
        FOR(j,1,N+1){
            int tmp;
            cin >> tmp;
            if(tmp == 1) set_union(i,j);
        }
    }

    possible();
    return 0;
}