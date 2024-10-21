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
    void solve(TreeNode* root)
    {
        if(root==NULL)return;
       solve(root->left);
       ans.push_back(root->val);
       solve(root->right);
        
    }
    void change(TreeNode* root,map<int,int>&mp)
    {
        if(root==NULL)return;
        root->val=mp[root->val];
        change(root->left,mp);
        change(root->right,mp);
    }
    TreeNode* convertBST(TreeNode* root) {
        solve(root);
        int sum = accumulate(ans.begin(),ans.end(),0);
        map<int,int> mp;
        for(int i=0;i<ans.size();i++)
        {
             mp[ans[i]]=sum;
             sum-=ans[i];
        }
        change(root,mp);
        return root;
    }
};