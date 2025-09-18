#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// There are two type of counting node based counting and edge based counting.
int height(TreeNode* root) {
    if (root == nullptr) return 0;  // node-based definition
    // if(root == nullptr) return -1; for edge based counting.

    return 1 + max(height(root->left), height(root->right));
}

// cleanup function to free memory
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    // Compute height
    cout << "Height of tree (node-based): " << height(root) << endl;

    // Free memory
    deleteTree(root);

    return 0;
}
