#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

unordered_map<string, int> token_map;
bool cmp_code(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

bool cmp_date(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}

bool cmp_maximum(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

bool cmp_remain(vector<int> a, vector<int> b) {
	return a[3] < b[3];
}

void init_token_map() {
	token_map["code"] = 0;
	token_map["date"] = 1;
	token_map["maximum"] = 2;
	token_map["remain"] = 3;
}

int tokenize(string ext) {
	return token_map[ext];
}

void push_data(int token, int val_ext, vector<vector<int>>& data, vector<vector<int>> &picked_vec) {
	for (int i = 0; i < data.size(); i++)
		if (data[i][token] <= val_ext)
			picked_vec.push_back(data[i]);
}

void sort_data(vector<vector<int>> &answer, string sort_by) {
	int token = tokenize(sort_by);
	switch (token)
	{
	case 0:
		sort(answer.begin(), answer.end(), cmp_code);
        break;
	case 1:
		sort(answer.begin(), answer.end(), cmp_date);
        break;
	case 2:
		sort(answer.begin(), answer.end(), cmp_maximum);
        break;
	case 3:
		sort(answer.begin(), answer.end(), cmp_remain);
        break;
	}
}

vector<vector<int>> pick_ext(vector<vector<int>> &data, string ext, int val_ext) {
	vector<vector<int>> picked_vec;

	int token = tokenize(ext);
	push_data(token, val_ext, data, picked_vec);

	return picked_vec;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
	vector<vector<int>> answer;

	init_token_map();
	answer = pick_ext(data, ext, val_ext);
	sort_data(answer, sort_by);
	return answer;
}
