#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_set<string> kinder;
unordered_map<string, int> classifier;
pair<int, int> ans;

int how_many_kind(vector<string> gems) {
    for (auto i : gems)
        kinder.insert(i);
    return kinder.size();
}

void is_there_all(vector<string> gems) {
    int kind_of = how_many_kind(gems);
    int point_st = 0, point_en = 0;

    for (auto gem : gems) {
        classifier[gem]++;
        if (classifier.size() == kind_of) break;
        point_en++;
    }
    
    int min_dist = point_en - point_st;
    ans.first = point_st + 1;
    ans.second = point_en + 1;

    while (point_en < gems.size()) {
        string cursor = gems[point_st];
        classifier[cursor]--; 
        point_st++; // 시작 포인터를 앞으로 옮김

        if (classifier[cursor] == 0) { // 없는 종류가 생기면
            point_en++; // 끝 포인터를 뒤로 옮김
            for (; point_en < gems.size(); point_en++) {
                classifier[gems[point_en]]++;
                if (cursor == gems[point_en]) break; // 없는 종류를 만나면 break;
            }
            if (point_en == gems.size()) break; // 마지막까지 가면 break
        }

        if (min_dist > (point_en - point_st)) {
            ans.first = point_st + 1;
            ans.second = point_en + 1;
            min_dist = point_en - point_st;
        }
    }
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    is_there_all(gems);
    answer.push_back(ans.first);
    answer.push_back(ans.second);

    return answer;
}
