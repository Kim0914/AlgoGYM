#include <string>

using namespace std;

string recur(string w){
    if(!w.size()) return "";
    
    int open = 0;
    int close = 0;
    bool correct = true;
    
    for(int i=0;i<w.size();i++){
        (w[i] == '(')? open++:close++;
        if(open - close < 0) correct = false;
        if(open - close == 0) break;
    }

    string u = w.substr(0,open+close);
    string v = w.substr(open+close,w.size()-open-close);

    if(correct) return u + recur(v);
    else{
        string newStr = "(" + recur(v) + ")";
        for(int i=1;i<open+close-1;i++){
            newStr += (u[i] == '(')? ')':'(';
        }
        return newStr;
    }
}

string solution(string p) {
    return recur(p);
}