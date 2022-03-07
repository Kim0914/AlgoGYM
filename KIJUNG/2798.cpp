#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N, M, tmp;
int maxi = 0;
vector<int> card;

void solution(){
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                tmp = card.at(i)+card.at(j)+card.at(k);
                if(M >= tmp && maxi<tmp) {
                    maxi = tmp;
                }
            }   
        }
    }
}

int main(void){
    // input
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> tmp;
        card.push_back(tmp);
    }

    solution();
    cout << maxi <<endl;

    return 0;
}