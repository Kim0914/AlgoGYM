#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define FOR(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int N;
string word;
vector<string> words;

bool myfun(string a, string b){
    if(a.length() != b.length()){
        return a.length()<b.length();
    }else{
        return a<b;
    }
}

int main(void){
    cin >> N;

    FOR(i,0,N){
        cin >> word;
        words.push_back(word);
    }

    sort(words.begin(), words.end(), myfun);
    words.erase(unique(words.begin(), words.end()), words.end());

    FOR(i,0,words.size()){ 
        cout << words[i] << "\n";
    }

    return 0;
}