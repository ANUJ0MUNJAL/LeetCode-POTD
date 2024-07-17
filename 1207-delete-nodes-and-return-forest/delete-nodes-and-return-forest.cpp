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
    vector<TreeNode*> ans;
    TreeNode* dfs(TreeNode* root,set<int> &st){
        if(root==NULL)return root;
       TreeNode* left= dfs(root->left,st);
       TreeNode* right= dfs(root->right,st);
        root->left=left;
        root->right=right;
        if(st.find(root->val)!=st.end()){
              if(root->left) ans.push_back(root->left);
              if(root->right) ans.push_back(root->right);
              return NULL;
        }

        return root;

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st(to_delete.begin(),to_delete.end());
        TreeNode* temp = dfs(root,st);
        for(int i=0;i<ans.size();i++){
            if(ans[i]->val == root->val){
                return ans;
            }
        }
        if(temp)
        ans.push_back(temp);
        return ans;
    }
};