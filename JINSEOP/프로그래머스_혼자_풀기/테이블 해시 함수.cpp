#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int standard = 0;
bool cmp(vector<int> &a, vector<int> &b) {
    if (a[standard] == b[standard])
        return a[0] > b[0];
    return a[standard] < b[standard];
}

void sort_by_column(vector<vector<int>>& data) {
    sort(data.begin(), data.end(), cmp);
}

int calculate_unit(vector<vector<int>> data, int row_num) {
    int sum = 0;

    for (int i : data[row_num - 1])
        sum += (i % row_num);

    return sum;
}

int calculate(vector<vector<int>> data, int row_begin, int row_end) {
    int xor_sum = 0;

    for (int i = row_begin; i <= row_end; i++)
        xor_sum ^= calculate_unit(data, i);

    return xor_sum;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    standard = col - 1;
    
    sort_by_column(data);
    answer = calculate(data, row_begin, row_end);

    return answer;
}
