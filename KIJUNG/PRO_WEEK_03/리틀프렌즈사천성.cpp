#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int y1, int x1, int y2, int x2, vector<string> &board){
    int minY = min(y1,y2);
    int maxY = max(y1,y2);
    int minX = min(x1,x2);
    int maxX = max(x1,x2);

    if(y1 == y2){
        for(int i=minX+1;i<maxX;i++){
            if(board[y1][i] != '.') return false;
        }
    }
    else if(x1 == x2){
        for(int i=minY+1;i<maxY;i++){
            if(board[i][x1] != '.') return false;
        }
    }
    else{
        bool flag1 = true;
        bool flag2 = true;
        bool flag3 = true;
        bool flag4 = true;
        
        for(int i=minX+1;i<maxX;i++){
            if(board[minY][i] != '.') flag1 = false;
        }
        for(int i=minY+1;i<maxY;i++){
            if(board[i][maxX] != '.') flag2 = false;
        }
        for(int i=minX+1;i<maxX;i++){
            if(board[maxY][i] != '.') flag3 = false;
        }
        for(int i=minY+1;i<maxY;i++){
            if(board[i][minX] != '.') flag4 = false;
        }
        
        if(flag1 && flag2 && board[minY][maxX] == '.') return true;
        if(flag3 && flag4 && board[maxY][minX] == '.') return true;
        if(flag2 && flag3 && board[maxY][maxX] == '.') return true;
        if(flag1 && flag4 && board[minY][minX] == '.') return true;
        
        return false;
    }
    return true;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    vector<pair<int,int> > alpaPoint[26];
    string answer = "";
    int cnt = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int mapping = (int)board[i][j]-65;
            if(mapping>=0 && mapping <=25){
                alpaPoint[mapping].push_back(make_pair(i,j));
                cnt++;
            }
        }
    }

    while(cnt){
        int beforeCnt = cnt;
        for(int i=0;i<=25;i++){
            if(alpaPoint[i].empty()) continue;
            int y1 = alpaPoint[i][0].first;
            int x1 = alpaPoint[i][0].second;
            int y2 = alpaPoint[i][1].first; 
            int x2 = alpaPoint[i][1].second;

            if(check(y1,x1,y2,x2,board)){
                board[y1][x1] = '.';
                board[y2][x2] = '.';
                alpaPoint[i].clear();
                answer += char(65+i);
                cnt -=2;
                break;
            }
        }
        if(beforeCnt == cnt) return "IMPOSSIBLE";
    }
    return answer;
}

int main(void){

    vector<string> v;
    v.push_back("M...M...DU");
    v.push_back("....AR...R");
    v.push_back("...E..OH.H");
    v.push_back(".....O....");
    v.push_back(".E..A..Q..");
    v.push_back("Q....LL.*.");
    v.push_back(".D.N.....U");
    v.push_back("GT.T...F..");
    v.push_back("....FKS...");
    v.push_back("GN....K..S");
    //AEFGHKLMDOQRSTNU

    cout << solution(10,10,v);
    
    return 0;
}