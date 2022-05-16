#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int n, m, parent[500000];

int set_find(int x){
    if(x == parent[x]) return x;
    else return parent[x] = set_find(parent[x]);
}

void set_union(int x, int y){
    int px = set_find(x);
    int py = set_find(y);

    if(px>py) parent[px] = py;
    else parent[py] = px;
}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    FOR(i,0,n){
        parent[i] = i;
    }
}

int sol(){
    FOR(i,0,m){
        int t1, t2;
        cin >> t1 >> t2;
        if(set_find(t1) == set_find(t2)) return i+1;
        else set_union(t1,t2);
    }
    return 0;
}

int main(void){
    init();
    cout << sol();
    return 0;
}