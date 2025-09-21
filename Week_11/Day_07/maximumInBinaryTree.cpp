#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

// if we consider the binary tree won't have negative numbers then we can just return -1 at root = nullptr.
int maximumInBinaryTree(TreeNode* root){
    if(root == nullptr){
        return INT_MIN;
    }

    int rootVal = root->val;

    return max(rootVal, max(maximumInBinaryTree(root->left), maximumInBinaryTree(root->right)));

}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->right = new TreeNode(60);

    cout << "Maximum value in the binary tree: " 
         << maximumInBinaryTree(root) << endl;

    // cleanup (delete allocated memory)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
