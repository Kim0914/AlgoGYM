#include <string>
#include <vector>
using namespace std;

string half_sound[6] = { "C#", "D#", "F#", "G#", "A#"};
string convert_to[6] = { "c", "d", "f", "g", "a"};
struct info {
    int play_time;
    string name;
    string music_sheet;
};

vector<info> parsed_info;
void convert_sharp(string& target, string src, string dest) {
    int idx = 0;
    while ((idx = target.find(src)) != string::npos)
        target.replace(idx, src.length(), dest);
}

int calc_play_time(string str, string end) {
    int st_hour = (str[0] - '0') * 10 + (str[1] - '0');
    int st_min = (str[3] - '0') * 10 + (str[4] - '0');
    int end_hour = (end[0] - '0') * 10 + (end[1] - '0');
    int end_min = (end[3] - '0') * 10 + (end[4] - '0');

    if (st_hour == end_hour) return end_min - st_min;
    else return 60 - st_min;
}

void info_parsing(vector<string> musicinfos) {
    string start_time;
    string end_time;

    for (auto musicinfo : musicinfos) {
        info temp;
        int cnt = 0;
        string temp_s = "";

        for (auto data : musicinfo) {
            if (data == ',') {
                switch (cnt)
                {
                case 0:
                    start_time = temp_s;
                    temp_s = "";
                    cnt++;
                    break;
                case 1:
                    end_time = temp_s;
                    temp_s = "";
                    cnt++;
                    break;
                case 2:
                    temp.name = temp_s;
                    temp_s = "";
                    cnt++;
                    break;
                }
            }
            else temp_s += data;
        }
        temp.music_sheet = temp_s;
        temp.play_time = calc_play_time(start_time, end_time);
        parsed_info.push_back(temp);
    }
}

void make_full_sheet() {
    for (auto& inf : parsed_info) {
        string temp = inf.music_sheet;
        int mod = inf.music_sheet.size();
        int iter = 0;

        if (temp.size() == inf.play_time) continue;
        while (temp.size() < inf.play_time) {
            temp += inf.music_sheet[iter%mod];
            iter++;
        }
        
        if (temp.size() > inf.play_time) {
            while (temp.size() != inf.play_time)
                temp.pop_back();
        }

        inf.music_sheet = temp;
    }
}

string find_music(string m) {
    pair<int, string> temp = {0, ""};

    for (auto inf : parsed_info) {
        if (inf.music_sheet.find(m) != string::npos && temp.first < inf.play_time) {
            temp.first = inf.play_time;
            temp.second = inf.name;
        }
    }

    return temp.second;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";

    for (int i = 0; i < 5; i++)
        convert_sharp(m, half_sound[i], convert_to[i]);

    info_parsing(musicinfos);

    for (auto& inf : parsed_info) {
        for (int i = 0; i < 5; i++)
            convert_sharp(inf.music_sheet, half_sound[i], convert_to[i]);
    }

    make_full_sheet();
    answer = find_music(m);
    if (answer == "") answer = "(None)";

    return answer;
}
