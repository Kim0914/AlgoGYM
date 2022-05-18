#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, cnt, parent[100001];
long long min_dist;
vector<array<int,3> > edge;
vector<pair<int,int> > xPlanet;
vector<pair<int,int> > yPlanet;
vector<pair<int,int> > zPlanet;

int findRoot(int v){
    if(parent[v] == v) return v;
    else return parent[v] = findRoot(parent[v]);
}

void unionRoot(int v1, int v2){
    parent[findRoot(v1)] = findRoot(v2);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    FOR(i,0,N){
        int x,y,z;
        cin >> x >> y >> z;
        xPlanet.push_back(make_pair(x,i));
        yPlanet.push_back(make_pair(y,i));
        zPlanet.push_back(make_pair(z,i));
        parent[i] = i;
    }

    sort(xPlanet.begin(), xPlanet.end());
    sort(yPlanet.begin(), yPlanet.end());
    sort(zPlanet.begin(), zPlanet.end());

    FOR(i,0,N-1){
        array<int,3> arr;
        arr[0] = xPlanet[i+1].first - xPlanet[i].first;
        arr[1] = xPlanet[i].second;
        arr[2] = xPlanet[i+1].second;
        edge.push_back(arr);

        arr[0] = yPlanet[i+1].first - yPlanet[i].first;
        arr[1] = yPlanet[i].second;
        arr[2] = yPlanet[i+1].second;
        edge.push_back(arr);

        arr[0] = zPlanet[i+1].first - zPlanet[i].first;
        arr[1] = zPlanet[i].second;
        arr[2] = zPlanet[i+1].second;
        edge.push_back(arr);
    }

    sort(edge.begin(), edge.end());

    FOR(i,0,edge.size()){
        if(findRoot(edge[i][1]) != findRoot(edge[i][2])){
            unionRoot(edge[i][1], edge[i][2]);
            cnt++;
            min_dist += (long long) edge[i][0];
        }
        if(cnt == N-1) break;
    }

    cout << min_dist;

    return 0;
}