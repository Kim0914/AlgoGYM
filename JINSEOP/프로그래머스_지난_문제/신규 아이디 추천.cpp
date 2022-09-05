#include <string>
#include <vector>
using namespace std;

void first_phase(string& new_id) {
    for (int i = 0; i < new_id.size(); i++) {
        if (isupper(new_id[i]))
            new_id[i] = tolower(new_id[i]);
    }
}

void second_phase(string& new_id) {
    int iter = 0;
    while(true) {
        if ((new_id[iter] < 'a' || new_id[iter] > 'z') 
            && (new_id[iter] < '0' || new_id[iter] > '9')
            && new_id[iter] != '-' && new_id[iter] != '_' && new_id[iter] != '.')
            new_id.erase(iter, 1);
        else iter++;

        if (iter >= new_id.size()) break;
    }
}

void third_phase(string& new_id) {
    int iter = 0;
    while (true) {
        if (new_id[iter] == '.') {
            if (new_id[iter + 1] == '.')
                new_id.erase(iter, 1);
            else iter++;
        }
        else iter++;

        if (iter >= new_id.size()) break;
    }
}

void fourth_phase(string& new_id) {
    if (new_id[0] == '.')
        new_id.erase(0, 1);
    if (new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.size() - 1, 1);
}

void fifth_phase(string& new_id) {
    if (new_id.size() == 0)
        new_id += 'a';
}

void sixth_phase(string& new_id) {
    int rm_part = new_id.size() - 15;

    if (new_id.size() >= 16)
        new_id.erase(15, rm_part);
    if (new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.size() - 1, 1);
}

void seventh_phase(string& new_id) {
    char add_char = new_id[new_id.size() - 1];

    if (new_id.size() <= 2) {
        while (new_id.size() < 3)
            new_id += add_char;
    }
}

string solution(string new_id) {
    first_phase(new_id);
    second_phase(new_id);
    third_phase(new_id);
    fourth_phase(new_id);
    fifth_phase(new_id);
    sixth_phase(new_id);
    seventh_phase(new_id);

    return new_id;
}
