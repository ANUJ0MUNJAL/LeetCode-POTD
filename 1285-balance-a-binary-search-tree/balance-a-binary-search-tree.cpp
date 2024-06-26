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
    vector<int> ans;
    void inorder(TreeNode *root){
          if(root == NULL)return;
          inorder(root->left);
          ans.push_back(root->val);
          inorder(root->right);
    }
    TreeNode* solve(vector<int> &ans,int start,int end){
         if(start == end) return new TreeNode(ans[start]);
         if(start > end)return NULL;
         int mid=start+(end-start)/2;
         TreeNode* root = new TreeNode(ans[mid]);
         root->left=solve(ans,start,mid-1);
         root->right=solve(ans,mid+1,end);
         return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return solve(ans,0,ans.size()-1);
    }
};