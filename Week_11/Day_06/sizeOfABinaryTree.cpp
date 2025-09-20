#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

int getSize(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return (1 + getSize(root->left) + getSize(root->right));
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Size of the tree: " << getSize(root) << endl;

    // Free allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
