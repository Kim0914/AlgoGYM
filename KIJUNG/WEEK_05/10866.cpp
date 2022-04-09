#include <iostream>
#include <deque>
#include <string>

using namespace std;

string str;
int N;
int nums[20001];
int b = 10000;
int e = 10000;

int main(void){
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> str;

        if(str == "push_front") cin >> nums[--b];
        else if(str == "push_back") cin >> nums[e++];
        else if(str == "pop_front") cout << ((e-b)? nums[b++]:-1) <<"aa\n";
        else if(str == "pop_back") cout << ((e-b)? nums[--e]:-1) <<"aa\n";
        else if(str == "size") cout << e-b << "aa\n";
        else if(str == "empty") cout << ((e-b)? 0:1) << "aa\n";
        else if(str == "front") cout << ((e-b)? nums[b]:-1) << "aa\n";
        else if(str == "back") cout << ((e-b)? nums[e-1]:-1) << "aa\n";
    }

    return 0;
}