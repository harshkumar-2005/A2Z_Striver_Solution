#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int helper(TreeNode *root, int &maxDiameter)
{
    if (root == nullptr)
        return -1; // height in edges

    int leftHeight = helper(root->left, maxDiameter);
    int rightHeight = helper(root->right, maxDiameter);

    int currDiameter = leftHeight + rightHeight + 2;
    maxDiameter = std::max(maxDiameter, currDiameter);

    return 1 + std::max(leftHeight, rightHeight); // height of this subtree
}

int diameterOfBinaryTree(TreeNode *root)
{
    int maxDiameter = 0;
    helper(root, maxDiameter);
    return maxDiameter;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of the tree: " << diameterOfBinaryTree(root) << endl;

    return 0;
}