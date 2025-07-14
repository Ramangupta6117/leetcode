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

    int diameter(TreeNode* root,map<TreeNode*, pair<int, int>>& mp){
        if(root==NULL){
            return 0;
        }
        int left = diameter(root->left,mp);
        int right = diameter(root->right,mp);
        mp[root] = {left,right};
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        map<TreeNode*, pair<int, int>> mp;
        diameter(root,mp);
        int maxi =0;
        for(auto& n : mp){
            maxi = max(maxi,n.second.first+n.second.second);
        }
        return maxi;
    }
};