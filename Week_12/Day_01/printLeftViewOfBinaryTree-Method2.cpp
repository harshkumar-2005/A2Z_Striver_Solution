#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Iterative method: print left view
void printLeft(TreeNode* root)
{
    if(root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        int count = q.size();
        for(int i = 0; i < count; i++)
        {
            TreeNode* curr = q.front();
            q.pop();

            // First node of each level
            if(i == 0)
                cout << curr->val << " ";

            if(curr->left != nullptr)
                q.push(curr->left);

            if(curr->right != nullptr)
                q.push(curr->right);
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Left view: ";
    printLeft(root);
    cout << "\n";

    return 0;
}
