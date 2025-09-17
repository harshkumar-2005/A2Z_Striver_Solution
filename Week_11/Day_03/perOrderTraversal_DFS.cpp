#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive pre-order traversal
// Root-Left-Right
void preOrder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    res.push_back(root->val);
    preOrder(root->left, res);
    preOrder(root->right, res);
}

TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();
    vector<int> result;
    preOrder(root, result);

    cout << "Pre-order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}