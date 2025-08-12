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
    int search(vector<int>& inorder,int left,int right,int val){
        for(int i=left;i<=right;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& preindex,int left, int right){
        if(left>right){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preindex]);

        int index = search(inorder,left,right,preorder[preindex]);
        preindex++;
        root->left=helper(preorder,inorder,preindex,left,index - 1);
        root->right=helper(preorder,inorder,preindex,index+1,right);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex = 0;
        return helper(preorder,inorder,preindex,0,inorder.size()-1);
    }
};