#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define FOR(i,a,b) for(int i =a;i<b;i++)

using namespace std;

int N, tmp;
// vector<int> nums;
int nums[1000001];
vector<int> sort_nums;
map<int,int> mapping;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    FOR(i,0,N){
        cin >> tmp;
        nums[i] = tmp;
        sort_nums.push_back(tmp);
    }

    sort(sort_nums.begin(), sort_nums.end());
    sort_nums.erase(unique(sort_nums.begin(),sort_nums.end()), sort_nums.end());

    // FOR(i,0,sort_nums.size()){
    //     mapping[sort_nums[i]] = i;
    // }

    // FOR(i,0,N){
    //     cout << mapping[nums[i]] << " ";//<< 맵핑시키는 자료구조 사용해야함.
    // }
    FOR(i,0,N){
        cout << lower_bound(sort_nums.begin(),sort_nums.end(), nums[i]) - sort_nums.begin() << " ";//<< 맵핑시키는 자료구조 사용해야함.
    }

    return 0;
}
//find해서 인덱스 값을 찾으니 시간초과 떴음 find함수의 시간복잡도가 n이라서 최종 n^2 시간복잡도를 가져서 그런것으로 생각됨.
//따라서 O(1)만에 연결되는 map자료구조를 사용함. > 통과

//lower_bound(vector.begin(), vector.end(), find_num) - vector.begin() 을 사용해서 find를 구현할 수 있다. <<정렬된 상태여야 함.
// !!!!!>> lower_bound 사용하니 map을 써서 구현했을 때 보다 두 배 넘게 줄어들었음!! 1000ms > 476ms. 공간복잡도는 1/3이 되었다. GOOD!
//vector의 push_back이 array에 값을 할당하는 것 보다 느리다 1200ms -> 1000ms. 