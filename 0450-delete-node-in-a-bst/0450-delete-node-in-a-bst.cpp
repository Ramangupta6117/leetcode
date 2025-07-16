/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* inorder(TreeNode* r){
    TreeNode* root = r;
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
        return NULL;
    }
    int x = root->val;
    if(x>key){
        root->left = deleteNode(root->left,key);
    }
    else if(x<key){
        root->right = deleteNode(root->right,key);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        TreeNode* ios = inorder(root->right);
        root->val = ios->val;
        root->right = deleteNode(root->right,ios->val);
    }
    return root;
    }
};