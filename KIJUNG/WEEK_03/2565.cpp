#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define FOR(i,a,b) for(int i = a; i<b; i++)

using namespace std;

int N;
vector<pair<int, int> > line;
pair<int, int> tmp3;
int cnt[100];
int cross[100][100];
int delCnt = 0;

int main(void){
    cin >> N;
    FOR(i,0,N){
        cin >> tmp3.first >> tmp3.second;
        line.push_back(tmp3);
    }
    // cout << "ok\n";

    FOR(i,0,N){
        FOR(j,0,N){
            if(line[i].first < line[j].first && line[i].second > line[j].second) {
                cross[i][j] = 1; cnt[i]++;
            }
            if(line[i].first > line[j].first && line[i].second < line[j].second) {
                cross[i][j] = 1; cnt[i]++;
            }
        }
    }
    // cout << "ok\n";

    FOR(i,0,N){
        cout << cnt[i] <<"\n";
    }

    while(1){
        int idx = max_element(cnt, cnt+N) - cnt;

        cout << "idx: "<<idx << "\n";

        if( cnt[idx] == 0) break;


        FOR(i,0,N){
            if( cross[i][idx] == 1){
                // cout << "i: "<<i << "idx: " << idx<<"\n";
                cross[i][idx] = 0;
                cnt[i]--;
            }
        }
        cnt[idx] = 0;
        delCnt++;
        
    }
    // cout << "ok\n";

    cout << delCnt;

    return 0;
}

//그리디 알고리즘으로는 못 푸는 문제. LIS로 풀자!
// 반례
// 10                                      
// 1 6
// 2 8
// 3 2
// 4 9
// 5 5
// 6 10
// 7 4
// 8 1
// 9 7
// 10 3
// 답: 6인데, 7나옴