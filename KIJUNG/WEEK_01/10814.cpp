#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int N;
int tmp;
string strtmp;
vector<string> clients_name;
vector<vector<int> > clients_info;
vector<int> client_age;

int main(void){
    cin >> N;

    FOR(i,0,N){
        cin >> tmp >> strtmp;
        client_age.push_back(tmp);
        client_age.push_back(i);
        clients_name.push_back(strtmp);
        clients_info.push_back(client_age);
        client_age.clear();
    }

    sort(clients_info.begin(),clients_info.end());

    FOR(i,0,N){
        cout << clients_info[i][0] << " " << clients_name[clients_info[i][1]] << "\n";
    }

    return 0;
}