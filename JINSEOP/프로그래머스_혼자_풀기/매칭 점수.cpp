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

int solution(string word, vector<string> pages) {
    int answer = 0;

    word = str_to_lowercase(word);
    for (int i = 0; i < pages.size(); i++) {
        string token = "";
        string web_index = "";

        for (int j = 0; j < pages[i].size(); j++) {
            if (pages[i][j] == ' ' || pages[i][j] == '\n' || pages[i][j] == '\t') {
                for (int k = 0; k < token.size(); k++)
                    token[k] = tolower(token[k]);

                if (token[0] == 'c') {
                    int content_idx = token.find("content");
                    if (content_idx != string::npos) {
                        bool start = false;
                        int start_idx = content_idx + 8;

                        for (int k = start_idx; k < token.size(); k++) {
                            if (!start && token[k] == '"') {
                                start = true;
                                continue;
                            }

                            if (start && token[k] == '"')
                                break;

                            web_index += token[k];
                        }
                    }
                }
                // 웹 인덱스 추출

                if (token == word)
                    website_info[web_index].first++;
                // 기본점수 계산

                if (token[0] == 'h') {
                    string external_web_index = "";
                    int href_idx = token.find("href");
                    if (href_idx != string::npos) {
                        bool start = false;
                        int start_idx = href_idx + 5;

                        for (int k = start_idx; k < token.size(); k++) {
                            if (!start && token[k] == '"') {
                                start = true;
                                continue;
                            }

                            if (start && token[k] == '"')
                                break;

                            external_web_index += token[k];
                        }

                        external_website_info[web_index].push_back(external_web_index);
                    }
                }

                token = "";
                continue;
            }

            token += pages[i][j];
        }

        website_list.push_back(web_index);
    }

    for (int i = 0; i < website_list.size(); i++) {
        string target_web = website_list[i];

        for (int j = 0; j < external_website_info[target_web].size(); j++) {
            string next_web = external_website_info[target_web][j];
            website_info[next_web].second += (website_info[target_web].first / external_website_info[target_web].size());
            // 연결된 웹의 기본 점수 / 외부 링크 수
        }
        // 링크 점수 계산
    }

    double max_match = 0;
    for (int i = 0; i < website_list.size(); i++) {
        string target_web = website_list[i];
        double match_score = website_info[target_web].first + website_info[target_web].second;

        if (match_score > max_match) {
            max_match = match_score;
            answer = i;
        }
    }
    // 매칭 점수 계산

    return answer;
}

int main() {
    solution("Muzi", { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", 
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>" });
	return 0;
}
