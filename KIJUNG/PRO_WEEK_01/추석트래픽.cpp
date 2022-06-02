#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

vector<pair<int,int> > linesMs;
int answer = 0;

int solution(vector<string> lines) {
    FOR(i,0,lines.size()){
        stringstream ss(lines[i]);
        string tmp = "";
        int msTmp = 0;
        pair<int,int> p;
        
        ss >> tmp;
        ss >> tmp;

        msTmp += stoi(tmp.substr(0,2)) * 60 * 60 * 1000;
        msTmp += stoi(tmp.substr(3,2)) * 60 * 1000;
        msTmp += stoi(tmp.substr(6,2)) * 1000;
        msTmp += stoi(tmp.substr(9,3));
        p.first = msTmp;

        ss >> tmp;
        msTmp -= (int) (stod(tmp.substr(0,tmp.size()-1))*1000);
        p.second = msTmp+1;
        
        linesMs.push_back(p);
    }

    sort(linesMs.begin(), linesMs.end());

    FOR(i,0,linesMs.size()){
        int cnt = 0;
        FOR(j,0,linesMs.size()){
            if(linesMs[i].first <= linesMs[j].first && linesMs[i].first + 999 >= linesMs[j].second){
                cnt++;
            }
        }
        answer = max(cnt, answer);
    }


    return answer;
}