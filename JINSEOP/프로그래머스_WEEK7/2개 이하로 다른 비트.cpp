#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string dec_to_bin(long long src) {
    string temp = "";
    int iter = 0;

    while (true) {
        temp += to_string(src % 2);
        if (src == 0) break;
        src /= 2; iter++;
    }
    
    reverse(temp.begin(), temp.end());
    return temp;
}

long long compare_bit(long long src, string bin_src) {
    string target = "";
    while (true) {
        int diff = 0;
        src++;
        target = dec_to_bin(src);

        if (target.size() > bin_src.size()) {
            reverse(bin_src.begin(), bin_src.end());
            for (int i = 0; i < (target.size() - bin_src.size()); i++)
                bin_src += '0';
            reverse(bin_src.begin(), bin_src.end());
        }

        int cmp_size = target.size() - 1;
        for (int i = 0; i < target.size(); i++)
            if (bin_src[i] != target[i]) diff++;

        if (diff <= 2) break;
    }

    return src;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++) {
        string bin_src;
        bin_src = dec_to_bin(numbers[i]);
        answer.push_back(compare_bit(numbers[i], bin_src));
    }

    return answer;
}
