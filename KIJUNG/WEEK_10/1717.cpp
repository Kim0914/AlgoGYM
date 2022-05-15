#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int n,m;
int parent[1000001];

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    FOR(i,1,n+1){
        parent[i] = i;
    }
    FOR(i,0,m){
        int oper, num1, num2;
        cin >> oper >> num1 >> num2;
        if(oper==0){
            set_union(num1, num2);
        }
        else {
            if(set_find(num1) == set_find(num2)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
