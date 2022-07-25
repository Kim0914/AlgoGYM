#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
        return a.first > b.first;
    }

string tolower(string str){
    for(int i = 0; i < str.size(); i++){
        if(65 <= str[i] && str[i] <= 90){
            str[i] += 32;
        }
    }
    return str;
}
bool is_in(string city, vector<pair<int, string>>& cache, int time){
    string low_city = tolower(city);
    for(int i = 0; i < cache.size(); i++){
        if(low_city == cache[i].second){
            cache[i].first = time;
            return true;
        } 
    }
    return false;
}

int solution(int cacheSize, vector<string> cities) {
   vector<pair<int, string>> cache;
    int answer = 0;
    if(cacheSize == 0){
        return cities.size() * 5;
    }
    for(int i = 0; i < cities.size(); i++){
        if(is_in(cities[i], cache, i)) answer += 1;
        else{
            answer += 5;
            if(cache.size() < cacheSize){
                cache.push_back(make_pair(i, tolower(cities[i])));
            }
            else{
                sort(cache.begin(), cache.end(),compare);
                cache.pop_back();
                cache.push_back(make_pair(i, tolower(cities[i])));
            }
        } 
    }
    return answer;
}
