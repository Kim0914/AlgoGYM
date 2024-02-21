#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
#define pdd pair<double, double>

unordered_map<string, pdd> website_info;
unordered_map<string, vector<string>> external_website_info;
vector<string> website_list;
string str_to_lowercase(string word) {
    string ret = word; 

    for (int i = 0; i < ret.size(); i++)
        ret[i] = tolower(ret[i]);

    return ret;
}

string find_current_url(string target_source) {
    // 현재 탐색중인 웹 페이지의 url을 반환한다.
    string target_tag = "<meta property=\"og:url\" content=\"https://";
    int tag_idx = target_source.find(target_tag);
    tag_idx += target_tag.size();

    string url = "";
    for (int i = tag_idx; i < target_source.size(); i++) {
        if (target_source[i] == '\"')
            break;

        url += target_source[i];
    }
    
    website_list.push_back(url);
    return url;
}

int search_word(string target_source, string word) {
    string target_open_tag = "<body>";
    string target_close_tag = "</body>";
    int target_open_idx = target_source.find(target_open_tag);
    int target_close_idx = target_source.find(target_close_tag);
    target_open_idx += target_open_tag.size();
    target_source = target_source.substr(target_open_idx, target_close_idx - target_open_idx);
    // substring 사용법 : substr(시작 위치, 문자열 길이)

    string token = "";
    int word_count = 0;
    for (int i = 0; i < target_source.size(); i++) {
        if (!isalpha(target_source[i])) {
        // 알파벳이 아닌 문자를 source 내에서 만나면 토큰화 시킨다.
            if (token == word)
                word_count++;
            token = "";
        }
        else
            token += target_source[i];
    }

    return word_count;
}

void find_external_url(string target_source, string curr_url) {
    string target_tag = "<a href=\"https://";
    int tag_idx = target_source.find(target_tag);

    while (tag_idx != string::npos) {
    // 외부링크가 여러개일 수 있으니, 반복해서 찾아야 함
        tag_idx += target_tag.size();

        string external_url = "";
        while(target_source[tag_idx] != '\"'){
            external_url += target_source[tag_idx];
            tag_idx++;
        }

        external_website_info[curr_url].push_back(external_url);
        target_source = target_source.substr(tag_idx);
        // 대상 소스를 잘라야 다음 외부 링크 탐색이 가능하다.
        tag_idx = target_source.find(target_tag);
    }
}

void calculate_link_score() {
    for (int i = 0; i < website_list.size(); i++) {
        string target_web = website_list[i];
        
        for (int j = 0; j < external_website_info[target_web].size(); j++) {
            string next_web = external_website_info[target_web][j];
            website_info[next_web].second += (website_info[target_web].first / external_website_info[target_web].size());
        }
    }
}

int calculate_match_score() {
    double max_match = 0;
    int max_idx = 0;

    for (int i = 0; i < website_list.size(); i++) {
        double match_score = 0;
        string target_web = website_list[i];
        match_score = website_info[target_web].first + website_info[target_web].second;

        if (match_score > max_match) {
            max_match = match_score;
            max_idx = i;
        }
    }

    return max_idx;
}

int solution(string word, vector<string> pages) {
    word = str_to_lowercase(word);
    for (int i = 0; i < pages.size(); i++) {
        string html_source = str_to_lowercase(pages[i]); // 전체 소문자 변환
        string curr_web_url = find_current_url(html_source); // 현재 페이지 url
        website_info[curr_web_url].first = search_word(html_source, word); // 기본 점수 계산
        find_external_url(html_source, curr_web_url); // 외부 링크 저장
    }

    calculate_link_score(); // 링크 점수 계산
    return calculate_match_score();
}
