#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int V, E, cnt, weight, parent[10001];
vector<array<int,3> > edge;

int findRoot(int x){
    if(parent[x] == x) return x;
    else return parent[x] = findRoot(parent[x]);
}

void unionRoot(int x, int y){
    parent[findRoot(x)] = findRoot(y);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;

    FOR(i,0,E){
        array<int,3> tmp;
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        edge.push_back(tmp);
    }

    FOR(i,1,V+1) parent[i]=i;

    sort(edge.begin(), edge.end());

    FOR(i,0,E){
        int v1 = edge[i][1];
        int v2 = edge[i][2];
        if(findRoot(v1) != findRoot(v2)){
            unionRoot(v1,v2);
            weight += edge[i][0];
            cnt++;
        }
        if(cnt == V-1) break;
    }

    cout << weight;


    return 0;
}