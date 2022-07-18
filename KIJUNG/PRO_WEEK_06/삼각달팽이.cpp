#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int tri[1001][1001];
    
    int cnt = 1;
    int num = n;
    int i=0, j=0;
    
    while(num>0){
        if(num%3 == n%3){
            for(int k=0;k<num;k++) tri[i++][j] = cnt++;
            i--;
        }
        else if(num%3 == (n+2)%3){
            for(int k=0;k<num;k++) tri[i][++j]=cnt++;
        }
        else{
            for(int k=0;k<num;k++) tri[--i][--j] = cnt++;
            i++;
        }
        num--;
    }

    for(int k = 0;k<n;k++){
        for(int l=0;l<=k;l++){
            answer.push_back(tri[k][l]);
        }
    }
    return answer;
}