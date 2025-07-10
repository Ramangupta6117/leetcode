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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int sum = 0;
        deque<TreeNode*> dq;
        if(root!=NULL){
            dq.push_back(root);
        }
        while(!dq.empty()){
            vector<int> v;
            int s = dq.size();
            for(int i=0;i<s;i++){
                TreeNode* x = dq.front();
                dq.pop_front();
                v.push_back(x->val);
                if(x->left != NULL) dq.push_back(x->left);
                if(x->right != NULL) dq.push_back(x->right);
            }
            ans.push_back(v[v.size()-1]);
        }
        return ans;
    }
};