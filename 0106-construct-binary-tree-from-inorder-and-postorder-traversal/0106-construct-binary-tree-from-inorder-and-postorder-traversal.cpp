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

    int postIndex;
    unordered_map<int, int> inorderMap;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderMap[rootVal];

        // Build right subtree first, then left
        root->right = build(inorder, postorder, inIndex + 1, inEnd);
        root->left = build(inorder, postorder, inStart, inIndex - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};