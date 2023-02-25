#include <string>
#include <vector>
#include <iostream>
using namespace std;

int leaf_node = 0, deleted_node = 0;
void dfs(int curr, vector<bool>& visit, vector<vector<int>> tree) {
    if (visit[curr])
        return;
    visit[curr] = true;

    if (tree[curr].size() == 0)
        leaf_node++;
    if (tree[curr].size() == 1 && tree[curr][0] == deleted_node)
        leaf_node++;

    for (int i = 0; i < tree[curr].size(); i++) {
        if (tree[curr][i] != deleted_node)
            dfs(tree[curr][i], visit, tree);
    }
}

int main() {
    int nodes = 0, root = 0;
    cin >> nodes;

    vector<vector<int>> tree(nodes, vector<int>());
    vector<bool> visit(nodes, false);

    for (int i = 0; i < nodes; i++) {
        int parent = 0;
        cin >> parent;

        if (parent == -1)
            root = i;
        else
            tree[parent].push_back(i);
    }

    cin >> deleted_node;

    if (deleted_node == root)
        cout << 0;
    else {
        dfs(root, visit, tree);
        cout << leaf_node;
    }

    return 0;
}
