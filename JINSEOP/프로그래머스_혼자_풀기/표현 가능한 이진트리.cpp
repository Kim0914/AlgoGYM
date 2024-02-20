#include <string>
#include <vector>
#include <iostream>
using namespace std;

string dec_to_bin(long long target){
    string bin = "";

    while (target != 0) {
        bin = to_string(target % 2) + bin;
        target /= 2;
    }

    return bin;
}

string bin_to_tree(string bin) {
    string bin_tree = bin;
    
    int trig = 2;
    while (true) {
        if (bin.size() <= (trig - 1)) {
            trig -= 1;
            break;
        }

        trig *= 2;
    }

    for (int i = 0; i < trig - bin.size(); i++)
        bin_tree = "0" + bin_tree;

    return bin_tree;
}

bool check_all_zero(string bin_tree) {
    // 부모 자식이 모두 0이면, 무조건 가능한 이진트리
    for (int i = 0; i < bin_tree.size(); i++)
        if (bin_tree[i] != '0')
            return false;

    return true;
}

bool validate_bin_tree(string bin_tree) {
    if (bin_tree.size() == 1 || check_all_zero(bin_tree))
        return true;

    int mid = bin_tree.size() / 2;
    string left = bin_tree.substr(0, mid); // 0 ~ mid
    string right = bin_tree.substr(mid + 1); // mid + 1 ~ end

    if (bin_tree[mid] == '1' && validate_bin_tree(left) && validate_bin_tree(right))
        return true;
    else
        return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    // 포화 이진트리의 생성이 가능할 조건
    // 1. 부모(Root)가 1이어야 함
    // 2. 부모(Root)가 0이면, 자식이 모두 0이어야 함

    for (int i = 0; i < numbers.size(); i++) {
        string bin_tree = bin_to_tree(dec_to_bin(numbers[i]));
        answer.push_back(validate_bin_tree(bin_tree));
    }
    
    return answer;
}
