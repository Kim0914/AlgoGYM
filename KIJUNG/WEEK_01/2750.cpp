#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int N, tmp;
vector<int> num;


int main(void){
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> tmp;
        num.push_back(tmp);
    }

    sort(num.begin(), num.end());
    for(int i=0; i<N; i++){
        cout << num.at(i) << endl;
    }


    return 0;
}