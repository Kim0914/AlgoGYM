#include <iostream>
#include <vector>

#define FOR(i,a,b) for(int i = a; i<b ; i++)

using namespace std;

int main(void){
    int N, tmp;
    vector<int> height;
    vector<int> weight;
    vector<int> rank(50);

    cin >> N;
    FOR(i,0,N){
        cin >> tmp;
        weight.push_back(tmp);
        cin >> tmp;
        height.push_back(tmp);
    }

    FOR(i,0,N){
        FOR(j,0,N){
            if(weight.at(i)<weight.at(j) && height.at(i)<height.at(j) ){
                rank.at(i)++;
            }
        }
    }

    FOR(i,0,N){
        cout << rank.at(i)+1 << " ";
    }

}