#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void printLeft(TreeNode* root, int level, int &maxLevel) {
    if (root == nullptr) return;

    // If visiting this level first time
    if (maxLevel < level) {
        cout << root->val << " ";
        maxLevel = level;
    }

    // Recurse left first, then right
    printLeft(root->left, level + 1, maxLevel);
    printLeft(root->right, level + 1, maxLevel);
}

int main() {
    // Build tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int maxLevel = 0;
    cout << "Left view: ";
    printLeft(root, 1, maxLevel);
    cout << "\n";

    return 0;
}
