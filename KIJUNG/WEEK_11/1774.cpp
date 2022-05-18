#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, M, cnt, parent[1001];
double min_dist;
vector<pair<int,int> > point;
vector<array<double,3> > edge;

int findRoot(int v){
    if(parent[v] == v) return v;
    else return parent[v] = findRoot(parent[v]);
}

void unionRoot(int v1, int v2){
    parent[findRoot(v1)] = findRoot(v2);
}

double ptop(pair<int,int> p1, pair<int,int> p2){
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return sqrt(pow(dx,2)+pow(dy,2));
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    point.push_back(make_pair(0,0));
    FOR(i,1,N+1){
        int x, y;
        cin >> x >> y;
        point.push_back(make_pair(x,y));
        parent[i] = i;
    }

    FOR(i,0,M){
        int t1,t2;
        cin >> t1 >> t2;
        unionRoot(t1,t2);
    }

    FOR(i,1,N){
        FOR(j,i+1,N+1){
            array<double,3> arr;
            arr[0] = ptop(point[i], point[j]);
            arr[1] = i;
            arr[2] = j;
            edge.push_back(arr);
        }
    }

    sort(edge.begin(), edge.end());

    FOR(i,0,edge.size()){
        if(findRoot(edge[i][1]) != findRoot(edge[i][2])){
            unionRoot(edge[i][1],edge[i][2]);
            min_dist +=edge[i][0];
            cnt++;
        }
        if(cnt == N-1) break;
    }

    // cout << min_dist;
    printf("%.2f \n",min_dist);

    return 0;
}