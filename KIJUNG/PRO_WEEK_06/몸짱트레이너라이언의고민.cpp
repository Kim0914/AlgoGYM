#include <vector>
#include <algorithm>

using namespace std;

bool check(int dist, int i, int j, vector<pair<int,int>> &v){
    for(pair<int,int> p:v){
        if(abs(i-p.first)+abs(j-p.second)<dist) return false; 
    }
    return true;
}

int solution(int n, int m, vector<vector<int>> timetable) {
    int answer = 0;
    int maxCnt = 0;
    
    for(int i=600;i<=1320;i++){
        int cnt = 0;
        for(vector<int> time: timetable){
            if(i>=time[0] && i<=time[1]) cnt++;
        }
        maxCnt = max(maxCnt, cnt);
    }
    if(maxCnt==1) return 0;
    
    for(int firstX=1;firstX<n+1;firstX++){
        for(int firstY=1;firstY<n+1;firstY++){
            for(int k=(n-1)*2;k>0;k--){
                vector<pair<int,int>> v;
                v.push_back(make_pair(firstX,firstY));
                for(int i=1;i<n+1;i++){
                    for(int j=1;j<n+1;j++){
                        if(check(k,i,j,v)) v.push_back(make_pair(i,j));
                    }
                }
                
                if(maxCnt<=v.size()) {
                    answer = max(answer,k);
                    break;
                }
            }
        }
    }
    
    return answer;
}