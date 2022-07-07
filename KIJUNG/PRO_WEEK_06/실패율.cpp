#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool myfun(pair<double, int> a, pair<double, int> b){
    if(a.first==b.first) return a.second<b.second;
    else return a.first>b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    map<int, int> m;
    map<int, int> sum;
    vector<pair<double, int>> v;

    for(int stage: stages) m[stage]++;
    sum[N+1] = m[N+1];

    for(int i=N;i>0;i--) sum[i] = sum[i+1] + m[i];
    for(int i=1;i<=N;i++){
        if(sum[i]==0) v.push_back(make_pair(0,i));
        else v.push_back(make_pair((double)m[i]/sum[i],i));
    }
    
    sort(v.begin(), v.end(), myfun);

    for(pair<double, int> p: v) answer.push_back(p.second);
    
    return answer;
}