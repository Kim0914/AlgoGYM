#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void){
    string str = "i am a valueable man";
    stringstream ss(str);
    
    string substr1;

    while(ss >> substr1){
        cout << substr1 << "\n";
    }

    return 0;
}