#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool check_key(vector<vector<int>> key, vector<vector<int>> lock){
    int limit = lock.size();
    for(int i = -limit + 1; i < limit; i++){
        for(int j = -limit + 1; j < limit; j++){
            vector<vector<int>> temp_lock = lock;
            for(int x = 0; x < key.size(); x++){
                for(int y = 0; y < key.size(); y++){
                    if((0 <= i + x && i + x < lock.size()) && (0 <= j + y && j + y < lock.size())){
                        temp_lock[x + i][y + j] += key[x][y];
                    }
                }
            }
            cout << endl;
            bool flag = true;
            for(int i = 0; i < lock.size(); i++){
                for(int j = 0; j < lock.size(); j++){
                    if(temp_lock[i][j] == 0 || temp_lock[i][j] == 2){
                        flag = false;
                        break;
                    }
                }
                if(flag == false) break;
            }
            if(flag) return true;
        }
    }
    return false;
}



bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    //no rotation
    vector<vector<int>> temp_key = key;
    if(check_key(key, lock)) return true;
    //rotation
    for(int i = 0; i < 3; i++){
        for(int k = 0; k < key.size(); k++){
           for(int z = 0; z < key.size(); z++){
                temp_key[k][z] = key[key.size()-z-1][k];
            }
        }
        key = temp_key;
        if(check_key(key, lock)) return true;
    }
    return false;
}
