#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int keyLen = key.size();
    vector<vector<vector<int> > > keys;

    keys.push_back(key);
    
    for(int k=1;k<4;k++){
        vector<vector<int> > keyTmp;
        for(int i=0;i<keyLen;i++){
            vector<int> tmp;
            for(int j=keyLen-1;j>=0;j--){
                tmp.push_back(keys[k-1][j][i]);
            }
            keyTmp.push_back(tmp);
        }
        keys.push_back(keyTmp);
    }

    int lockRowStart = 0;
    int lockRowEnd = lock.size()-1;
    int lockColStart = lock[0].size()-1;
    int lockColEnd = 0;

    for(int i=0;i<lock.size();i++){
        if(lock[i].end() != find(lock[i].begin(),lock[i].end(),0)) break;
        lockRowStart++;
    }

    for(int i=lock.size()-1; i>=lockRowStart; i--){
        if(lock[i].end() != find(lock[i].begin(),lock[i].end(),0)) break;
        lockRowEnd--;
    }

    for(int i=0; i<lock.size(); i++){
        for(int j=0; j<lock[0].size(); j++){
            if(lock[i][j] == 0) {
                lockColStart = min(j,lockColStart);
                break;
            }
        }
    }

    for(int i=0; i<lock.size(); i++){
        for(int j=lock[0].size()-1; j>=0; j--){
            if(lock[i][j] == 0) {
                lockColEnd = max(j,lockColEnd);
                break;
            }
        }
    }
    
    if(lockRowStart > lockRowEnd) return true;
    
    vector<vector<int>> newLock;
    
    for(int i=lockRowStart; i<=lockRowEnd; i++){
        vector<int> tmp;
        for(int j=lockColStart; j<=lockColEnd; j++){
            tmp.push_back(lock[i][j]);
        }
        newLock.push_back(tmp);
    }
    
    for(vector<vector<int>> keyE: keys){
        for(int i=0; keyLen>=i+newLock.size(); i++){
            for(int j=0; keyLen>=j+newLock[0].size(); j++){
                bool flag=true;

                for(int y=0; y<newLock.size(); y++){
                    for(int x=0; x<newLock[0].size(); x++){
                        if(!((newLock[y][x] == 0 && keyE[i+y][j+x] == 1) || (newLock[y][x] == 1 && keyE[i+y][j+x] == 0))) {
                            flag = false;
                            break;
                        }
                        if(!flag) break;
                    }
                }
                if(flag) return true;

            }
        }
    }

    return false;
}