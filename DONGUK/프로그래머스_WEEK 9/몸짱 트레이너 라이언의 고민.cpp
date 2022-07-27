#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int calcDistance(int x1, int y1, int x2, int y2){
    return abs(x2 - x1) + abs(y2 - y1);
}

bool check(int x2, int y2, int maxDistance, vector<pair<int, int>> &people){
    for (pair<int, int> p : people){
        if (calcDistance(p.first, p.second, x2, y2) < maxDistance){
            return false;
        }
    }

    return true;
  }


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> timetable) {
    
    int maxCnt = 0;
    int maxTime = 0;
    
    for(int i=600; i<=1320; i++){
        int cnt = 0;
        for(vector<int> time : timetable){
            if (time[0] <= i && time[1] >= i){
                cnt++;
            }
        }
        
        if(cnt > maxCnt){
            maxCnt = cnt;
            maxTime = i;
        }
    }
    int answer = 0;
    
    if(maxCnt <= 1){
        return answer;
    }
    
    else{
        // 최대 거리부터 확인
        for(int dis = 2*(n-1); dis > 0; dis--){
            
            for(int x=0; x<n; x++){
                for(int y=0; y<n; y++){
                    
                    vector<pair<int ,int>> people;
                    people.push_back(make_pair(x, y));
                    
                    for(int x2 = x; x2 < n; x2++){
                        for(int y2 = 0; y2 < n; y2++){
                            if(x2 == x && y2 == y){
                                continue;
                            }
                            
                            if(check(x2, y2, dis, people)){
                                people.push_back(make_pair(x2, y2));
                            }
                            
                            if(people.size() == maxCnt){
                                return dis;
                            }
                            
                        }
                    }
                    
                }
            }
        }
        
    }
    
    return answer;
}