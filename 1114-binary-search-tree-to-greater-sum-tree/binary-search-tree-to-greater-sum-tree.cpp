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
    int value=0;
    void solve(TreeNode* root){
         if(root==NULL)return;
         solve(root->left);
         value+=root->val;
         solve(root->right);

    }
    void inorder(TreeNode * root,int &sum){
            if(root == NULL)return;
            inorder(root->left,sum);
            int val=sum;
           
            sum-=root->val;
            
            root->val=val;
           
            inorder(root->right,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
           inorder(root,value);
          return root;
    }
};