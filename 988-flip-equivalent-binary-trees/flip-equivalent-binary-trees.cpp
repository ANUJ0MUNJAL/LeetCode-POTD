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
    map<int,int> mp;
    void solve(TreeNode* root)
    {
        if(root == nullptr)return;
        solve(root->left);
        if(root->left)mp[root->left->val]=root->val;
        if(root->right)mp[root->right->val]=root->val;
        solve(root->right);
    }
    bool check(TreeNode* root)
    {
        if(root==nullptr)return true;
        bool left=check(root->left);
        bool right=check(root->right);
        if(root->left)
        {
            if(mp.count(root->left->val) == 0)return false;
            if(mp[root->left->val] != root->val)return false;
            mp.erase(root->left->val);
        }
        if(root->right)
        {
            if(mp.count(root->right->val) == 0)return false;
            if(mp[root->right->val] != root->val)return false;
            mp.erase(root->right->val);
        }
        return left and right;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        solve(root1);
        if(root1==nullptr and root2==nullptr)return true;
        if(root1==nullptr and root2)return false;
        if(root1 and root2==nullptr)return false;
        if(root1->val != root2->val)return false;
        return check(root2) && mp.size()==0;
    }
};