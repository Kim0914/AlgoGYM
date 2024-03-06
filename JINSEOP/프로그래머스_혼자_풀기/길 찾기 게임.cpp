#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define piii pair<int, pair<int, int>>

vector<int> inorder_vec;
vector<int> postorder_vec;
struct Node {
    int x;
    int idx;
    Node* left_child;
    Node* right_child;

    Node(int x, int idx, Node* left_child, Node* right_child) {
        this->x = x;
        this->idx = idx;
        this->left_child = left_child;
        this->right_child = right_child;
    }
};

bool cmp(piii a, piii b) {
    if (a.second.second == b.second.second)
        return a.second.first < b.second.first;
    return a.second.second > b.second.second;
    // Y축 우선 정렬, 이후 X축 차선 정렬
}

void insert_node(Node *curr_node, Node *new_node) {
    if (curr_node->x <= new_node->x) {
    // 현재 노드의 x값이 새 노드보다 작은 경우
        if (curr_node->right_child == NULL)
            curr_node->right_child = new_node;
        // 현재 노드의 오른쪽 자식이 비었으면 추가
        else if (curr_node->right_child != NULL)
            insert_node(curr_node->right_child, new_node);
        // 현재 노드의 오른쪽 자식이 비지 않았으면 이동
    }
    else {
    // 현재 노드의 x값이 새 노드보다 큰 경우
        if (curr_node->left_child == NULL)
            curr_node->left_child = new_node;
        else if (curr_node->left_child != NULL)
            insert_node(curr_node->left_child, new_node);
    }
}

void inorder(Node *curr_node) {
    inorder_vec.push_back(curr_node->idx);

    if(curr_node->left_child != NULL)
        inorder(curr_node->left_child);
    if(curr_node->right_child != NULL)
        inorder(curr_node->right_child);
}

void postorder(Node* curr_node) {
    if (curr_node->left_child != NULL)
        postorder(curr_node->left_child);
    if (curr_node->right_child != NULL)
        postorder(curr_node->right_child);

    postorder_vec.push_back(curr_node->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    vector<piii> node_info;
    for (int i = 1; i <= nodeinfo.size(); i++)
        node_info.push_back({i, {nodeinfo[i - 1][0], nodeinfo[i - 1][1]}});
    // 인덱스, x좌표(좌, 우), y좌표(깊이)
    sort(node_info.begin(), node_info.end(), cmp);

    Node *root = new Node(node_info[0].second.first, node_info[0].first, NULL, NULL);
    for (int i = 1; i < node_info.size(); i++)
        insert_node(root, new Node(node_info[i].second.first, node_info[i].first, NULL, NULL));

    inorder(root);
    answer.push_back(inorder_vec);
    postorder(root);
    answer.push_back(postorder_vec);

    return answer;
}
