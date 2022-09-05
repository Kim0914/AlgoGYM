#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<string, int> suspect_list;
unordered_map<string, int> reporter_list;
unordered_set<string> duplication_remover;

void init_remover(vector<string> report) {
    for (string s : report)
        duplication_remover.insert(s);
}

void count_declared() {
    for (string s : duplication_remover) {
        int space = s.find(" ");
        suspect_list[s.substr(space + 1, s.size() - space - 1)]++;
    }
}

void count_report(int k) {
    for (auto s : duplication_remover) {
        int space = s.find(" ");
        string reporter = s.substr(0, space);
        string suspect = s.substr(space + 1, s.size() - space - 1);
        
        if (suspect_list[suspect] >= k) reporter_list[reporter]++;
    }
}

void count_mail(vector<string> id_list, vector<int>& answer) {
    for (string name : id_list)
        answer.push_back(reporter_list[name]);
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    init_remover(report);
    count_declared();
    count_report(k);
    count_mail(id_list, answer);

    return answer;
}
