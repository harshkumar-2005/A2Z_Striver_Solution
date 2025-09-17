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

// Recursive post-order traversal
// Left-Right-Root
void postOrder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    postOrder(root->left, res);
    postOrder(root->right, res);
    res.push_back(root->val);
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
    postOrder(root, result);

    cout << "Post-order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}