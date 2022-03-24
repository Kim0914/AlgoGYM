#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define FOR(i,a,b) for(int i = a; i<b; i++)

using namespace std;

int N, tmp, tmp2;
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

    // FOR(i,0,N){
    //     cout << cnt[i] <<"\n";
    // }

    while(1){
        int idx = max_element(cnt, cnt+N) - cnt;

        // cout << "idx: "<<idx << "\n";

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