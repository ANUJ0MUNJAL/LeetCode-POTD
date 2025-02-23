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
    int index1=0,index2=0;
    TreeNode* solve(vector<int>&preorder,vector<int>&postorder)
    {
          TreeNode* root = new TreeNode(preorder[index1++]);
          if(root->val != postorder[index2])
             root->left = solve(preorder,postorder);
          if(root->val != postorder[index2])
             root->right = solve(preorder,postorder);
          index2++;
          return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return solve(preorder,postorder);
    }
};