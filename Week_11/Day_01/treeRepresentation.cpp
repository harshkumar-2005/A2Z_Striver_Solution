struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        data = x;
        left = right = nullptr;
    }
};

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->left->right->left = new TreeNode(70);
    root->left->right->right = new TreeNode(80);

    root->right = new TreeNode(30);
    root->right->right = new TreeNode(60);

    return 0;
}

/*
    tree representation:- 

            10
          /    \
        20      30
       /  \       \
     40    50      60
          /  \
        70    80
*/
 