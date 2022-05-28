#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define INF 100000000

using namespace std;

int T, n, m, t, s, g, h, a, b, d, x, ness, ans, dis[2001];
vector<pair<int,int> > edge[2001];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;

int ds(int start, int end){

    fill_n(dis+1,n,INF);
    dis[start] = 0;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        

        FOR(i,0,edge[cur].size()){
            int next = edge[cur][i].first;
            int nCost = edge[cur][i].second;

            if(dis[next] > cost + nCost){
                dis[next] = cost + nCost;
                pq.push(make_pair(dis[next],next));
            }
        }
    }
    return dis[end];
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    cin >> T;
    FOR(l,0,T){
        vector<int> arrive;

        FOR(i,1,2000) edge[i].clear();        

        cin >> n >> m >> t >> s >> g >> h;
        FOR(i,0,m){
            cin >> a >> b >> d;
            edge[a].push_back(make_pair(b,d));
            edge[b].push_back(make_pair(a,d));
            if((a==g && b==h) || (a==h && b==g)) ness = d;
        }
        //logic

        FOR(i,0,t){
            cin >> x;
            if(ds(s,x) == ds(s,g) + ds(h,x) + ness || ds(s,x) == ds(s,h) + ds(g,x) + ness)
                arrive.push_back(x);
        }

        sort(arrive.begin(), arrive.end());

        FOR(i,0,arrive.size()){
            cout << arrive[i] << " ";
        }
        cout << "\n";
    }

}