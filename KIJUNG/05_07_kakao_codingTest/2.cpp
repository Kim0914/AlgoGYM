#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;
vector<int> v;
vector<int> p1v;
vector<int> p2v;

int solution(vector<int> queue1, vector<int> queue2) {
    int qSize = queue1.size();
    FOR(i,0,queue1.size()) v.push_back(queue1[i]);
    FOR(i,0,queue2.size()) v.push_back(queue2[i]);

    long long sum = 0;
    FOR(i,0,v.size()){
        sum += v[i];
    }
    sum /= 2;

    // cout << "sum : " << sum << "\n"; 
    int point1 = 0;
    int point2 = 0;
    long long tmpSum=v[0];

    while(point1<v.size() && point2<v.size()){
        if(tmpSum < sum){
            tmpSum += v[++point2];
        }
        else if(tmpSum > sum){
            tmpSum -= v[point1++];

        }
        else{
            p1v.push_back(point1);
            p2v.push_back(point2+1);
            tmpSum -= v[point1++];
        }
    }

    if(p1v.empty()) return -1;
    else{
        int m = 1000000;
        FOR(i,0,p1v.size()){
            // cout << p1v[i] << " " << p2v[i] << "\n";
            if(p1v[i]<queue1.size()){
                if(p2v[i]<queue1.size()){
                    if(p2v[i]==queue1.size()-1) {
                        m = min(m, p1v[i]);
                        continue;
                    }
                    else m = min(p1v[i] + p2v[i] + qSize, m);
                }
                else m = min(p1v[i] + p2v[i] - qSize, m);
            }
            else{
                if(p2v[i] == v.size()) m = min(p1v[i]-qSize, m);
                else m = min(p1v[i] + p2v[i] - qSize , m);
            }
        }
        return m;
    }

    return 0;
}