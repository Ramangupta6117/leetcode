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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> dq;
        int lev = 0;
        if(root != NULL){
            dq.push_back(root);
        }
        while(!dq.empty()){
            vector<int>v;
            int levelsize = dq.size();
            for(int i =0;i<levelsize;i++){
                TreeNode* current = dq.front();
                dq.pop_front();
                v.push_back(current->val);
                if(current->left != NULL) dq.push_back(current->left);
                if(current->right != NULL) dq.push_back(current->right);
            }
            if(lev%2!=0){
            reverse(v.begin(),v.end());
            }
            ans.push_back(v);
            lev++;
        }
        return ans;
    }
};