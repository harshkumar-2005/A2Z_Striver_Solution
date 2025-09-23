// A tree is height-balanced if the difference between the heights of left and right subtrees is not more than one for all nodes of the tree.

#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + std::max(height(root->left), height(root->right));
}

bool isBalanced(TreeNode *root)
{
    int heightLeft = height(root->left);
    int heightRight = height(root->right);

    if (abs(heightLeft - heightRight) > 1)
    {
        return false;
    }

    // must also check subtrees
    return isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    if (isBalanced(root))
    {
        std::cout << "The tree is balanced" << std::endl;
    }
    else
    {
        std::cout << "The tree is NOT balanced" << std::endl;
    }

    return 0;
}