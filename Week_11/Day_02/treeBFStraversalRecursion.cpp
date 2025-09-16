#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void bfs(TreeNode* root, int level, vector<vector<int>>& res) {
    if (root == nullptr) return; // base case

    if (res.size() == level) {
        res.push_back({});
    }

    res[level].push_back(root->val);

    bfs(root->left, level + 1, res);
    bfs(root->right, level + 1, res);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    bfs(root, 0, res);
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    vector<vector<int>> res = levelOrder(root);

    for (int i = 0; i < res.size(); i++) {
        for (int val : res[i]){
            cout << val << " ";
        }
        cout << endl;
    }
}
