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
    
     int solve(TreeNode * root,int &count)
    {
          if(root==NULL)return 0;
          
          int left=solve(root->left,count);
          int right=solve(root->right,count);
          
          int first=0,second=0;
          if(root->left)
          {
             if(root->left->val == root->val)
                first=left+1;
            
          }
          if(root->right)
          {
              if(root->right->val == root->val)
                second=right+1;
          }
          count=max({count,first+second});
          return max(first,second);

          

        
    }
    int longestUnivaluePath(TreeNode* root) {
         if(root==NULL)return 0;
         int count=0;
         solve(root,count);
         return count;
    }
};