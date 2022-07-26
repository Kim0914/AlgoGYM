#include <string>
#include <vector>
using namespace std;

struct block {
    string data;
    int refer;
};

int work_time = 0, cnt = 1;
void initiate(vector<block>& cache, vector<string>& cities) {
    for (int i = 0; i < cities.size(); i++)
        for (int j = 0; j < cities[i].size(); j++)
            cities[i][j] = tolower(cities[i][j]);

    for (int i = 0; i < cache.size(); i++) {
        block temp;
        temp.data = "NULL"; temp.refer = 0;
        cache[i] = temp;
    }
}

int LRU(vector<block> cache) {
    int min_refer = 99999999;
    int min_idx = 0;

    for (int i = 0; i < cache.size(); i++) {
        if (cache[i].refer < min_refer) {
            min_refer = cache[i].refer;
            min_idx = i;
        }
    }

    return min_idx;
}

void cache_work(vector<block>& cache, vector<string> cities) {
    int min_idx = 0;

    for (int i = 0; i < cities.size(); i++) {
        bool hit = false, vacant = false;
        for (int j = 0; j < cache.size(); j++) {
            if (cache[j].data == cities[i]) {
                hit = true;
                work_time += 1;
                cache[j].refer = cnt; cnt++; break;
            }

            if (cache[j].data == "NULL") {
                vacant = true;
                cache[j].data = cities[i];
                cache[j].refer = cnt;
                work_time += 5; cnt++; break;
            }
        }


        if (!hit && !vacant) {
            min_idx = LRU(cache);
            cache[min_idx].data = cities[i];
            cache[min_idx].refer = cnt;
            cnt++; work_time += 5;
        }
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    vector<block> cache(cacheSize);
    initiate(cache, cities);

    if (cacheSize == 0) answer = cities.size() * 5;
    else {
        cache_work(cache, cities);
        answer = work_time;
    }

    return answer;
}
