#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int n, cnt, parent[100];
double m;
vector<pair<double, double> > stars;
vector<array<double,3> > edge;

double dist(pair<int, int> s1, pair<int, int> s2){
    int dx = s1.first - s2.first;
    int dy = s1.second - s2.second;

    return sqrt(pow(dx,2) + pow(dy,2));
}

int findRoot(int v){
    if(parent[v] == v) return v;
    else return parent[v] = findRoot(parent[v]);
}

void unionRoot(int v1, int v2){
    parent[findRoot(v1)] = findRoot(v2);
}

int main(void){
    cin >> n;
    FOR(i,0,n){
        pair<double, double> star;
        cin >> star.first >> star.second;
        stars.push_back(star);
        parent[i] = i;
    }
    FOR(i,0,n-1){
        FOR(j,1,n){
            array<double, 3> arr;
            arr[0] = dist(stars[i], stars[j]);
            arr[1] = i;
            arr[2] = j;
            edge.push_back(arr);
        }
    }

    sort(edge.begin(), edge.end());

    FOR(i,0,edge.size()){
        if(findRoot(edge[i][1]) != findRoot(edge[i][2])){
            unionRoot(edge[i][1], edge[i][2]);
            cnt++;
            m += edge[i][0];
        }
        if(cnt == n-1) break;
    }

    printf("%.2f", m);

    return 0;
}