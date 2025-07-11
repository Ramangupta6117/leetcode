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
    bool pathsum(TreeNode* root,int targetsum,int sum){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL&&root->right==NULL){
            return targetsum == sum+root->val;
        }
        bool left = pathsum(root->left,targetsum,sum+root->val);
        bool right = pathsum(root->right,targetsum,sum+root->val);
        return left||right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
       return pathsum(root,targetSum,0);
    }
};