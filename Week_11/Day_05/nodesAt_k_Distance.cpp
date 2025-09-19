#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void helper(TreeNode *root, int k, vector<int> &res)
{
    if (root == nullptr)
        return;

    if (k == 0)
    {
        res.push_back(root->val);
    }
    else
    {
        helper(root->left, k - 1, res);
        helper(root->right, k - 1, res);
    }
}

vector<int> nodesAtk(TreeNode *root, int k)
{
    vector<int> res;
    helper(root, k, res);

    return res;
}

int main()
{
    int k = 2;

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(20); 
    root->left->left = new TreeNode(40); 
    root->left->right = new TreeNode(50);
    
    root->right = new TreeNode(30);
    root->right->right = new TreeNode(70);

    vector<int> res = nodesAtk(root, k);

    for(int x : res)
    {
        cout<<x<<" ";
    }

    return 0;
}