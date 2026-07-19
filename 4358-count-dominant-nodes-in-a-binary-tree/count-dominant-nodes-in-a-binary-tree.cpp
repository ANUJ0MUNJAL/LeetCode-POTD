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
    int count = 0;
    int solve(TreeNode* root)
    {  
        if(root == nullptr)return 0;
        if(root->left==nullptr and root->right==nullptr)
        {
            count++;
            return root->val;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        if(root->val >= max(left,right))count++;

        return max({left,right,root->val});
    }
    int countDominantNodes(TreeNode* root) {
        solve(root);
        return count;
    }
};