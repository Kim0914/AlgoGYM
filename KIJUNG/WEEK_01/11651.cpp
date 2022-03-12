#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FOR(i,a,b) for(int i = a; i<b; i++)

using namespace std;

int N;
array<int,2> point = {0,};
vector<array<int,2> > points;

int main(void){
    cin >> N;
    FOR(i,0,N){
        cin >> point[1] >> point[0];
        points.push_back(point);
    }

    sort(points.begin(),points.end());

    FOR(i,0,N){
        cout << points[i][1] << " " << points[i][0] << "\n" ;
    }

    return 0;
}
//시간 복잡도: nlog(n)
//공간 복잡도: 2n