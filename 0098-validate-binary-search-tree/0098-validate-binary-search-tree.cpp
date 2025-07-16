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
    bool dfs(TreeNode* root,TreeNode* min,TreeNode* max){
        if(root==NULL){
            return true;
        }
        if(max!=NULL && root->val >= max->val){
            return false;
        }
        if(min!= NULL && root->val<=min->val){
            return false;
        }
        bool left = dfs(root->left,min,root);
        bool right = dfs(root->right,root,max);

        return left && right;
    }
    
    bool isValidBST(TreeNode* root) {
        return dfs(root,NULL,NULL);
    }
};