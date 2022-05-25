#include <iostream>
#include <algorithm>

#define FOR(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int n, preOrder[10001], inOrder[10001], inOrderIdx[1000001];

void postOrder(int i_s, int i_e, int p_s, int p_e){
    if(i_s>i_e || p_s>p_e) return;

    int pivot = inOrderIdx[preOrder[p_s]];
    int leftSize = pivot-i_s;
    int rightSize = i_e-pivot;

    postOrder(i_s,i_s+leftSize-1, p_s+1, p_s+leftSize);
    postOrder(i_s+leftSize+1, i_e, p_e-rightSize+1, p_e);

    cout << preOrder[p_s] << "\n";
}

int main(void){
    int tmp;
    while(cin >> tmp){
        if(tmp != EOF){
            preOrder[n] = tmp;
            inOrder[n] = tmp;
            n++;
        }
    }
    
    sort(inOrder, inOrder+n);

    FOR(i,0,n){
        inOrderIdx[inOrder[i]] = i;
    }

    postOrder(0,n-1,0,n-1);


    return 0;
}