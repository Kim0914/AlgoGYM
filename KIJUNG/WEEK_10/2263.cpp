#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int N, inOrderMap[100001], inOrder[100001], postOrder[100001];

void preOrder(int inS, int inE, int postS, int postE){
    if(postS > postE ) return;
    int parentIdx = inOrderMap[postOrder[postE]];
    int leftSize = parentIdx-inS;
    int rightSize = inE-parentIdx;

    cout << postOrder[postE] << " ";
    preOrder(inS, parentIdx-1, postS, postS+leftSize-1);
    preOrder(parentIdx+1, inE, postE-rightSize, postE-1);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    FOR(i,1,N+1) {
        cin >> inOrder[i];
        inOrderMap[inOrder[i]] = i;
    }
    FOR(i,1,N+1) cin >> postOrder[i];

    preOrder(1,N,1,N);

    return 0;
}