#include <string>
#include <vector>
#include <sstream>
#include <map>

#define FOR(i,a,b) for(int i=a,i<b;i++)

using namespace std;
map<string, int> mappingTable;
map<string, int> reportN;
vector<vector<string> > reporter;
vector<int> answer;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    //신고당한 횟수 초기화
    FOR(i,0,id_list.size()){
        vector<string> initVec;
        reporter[id_list[i]] = initVec;
        reportN[id_list[i]] = 0;
        mappingTable[id_list[i]] = i;

    }

    //누가 누구를 신고했는가 vector에 있으면 추가하지 않음
    FOR(i,0,report.size()){
        stringstream ss(report[i]);
        string tmpReporter;
        string tmpReported;

        ss>>tmpReporter;
        ss>>tmpReported;

        if(count(reporter[tmpReporter].begin(),reporter[tmpReporter].end,tmpReported) == 0){
            reporter[mappingTable[tmpReporter]].push_back(tmpReported);
            reportN[tmpReported]++;
        }
    }

    FOR(i,0,id_list.size()){
        FOR(j,0,reporter[id_list[i]].size()){
            if(reportN[reporter[i]][j] >= k) answer[i]++;
        }
    }
    
    return answer;
}