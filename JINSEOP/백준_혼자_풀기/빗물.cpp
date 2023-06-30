#include <iostream>
#include <vector>
using namespace std;

vector<int> historgram;
int main() {
    int height = 0, width = 0, block = 0, total_rain = 0;

    cin >> height >> width;
    for (int i = 0; i < width; i++) {
        cin >> block;
        historgram.push_back(block);
    }

    for (int i = 1; i < width - 1; i++) {
        int left = 0, right = 0;

        for (int j = 0; j < i; j++)
            left = max(left, historgram[j]);
        for (int j = i; j < width; j++)
            right = max(right, historgram[j]);

        total_rain += max(0, min(left, right) - historgram[i]);
    }

    cout << total_rain << endl;

    return 0;
}
