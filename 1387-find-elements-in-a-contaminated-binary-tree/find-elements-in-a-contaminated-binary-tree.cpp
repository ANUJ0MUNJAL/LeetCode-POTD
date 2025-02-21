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
class FindElements {
public:
    set<int> st;
    void solve(TreeNode * root)
    {
        if(root == nullptr)return ;
        if(root->left){
            root->left->val = 2 *(root->val) +1;
            st.insert(root->left->val);
        }
        if(root->right){
           root->right->val = 2*(root->val)+2;
           st.insert(root->right->val);
        }
        solve(root->left);
        solve(root->right);

    }
    FindElements(TreeNode* root) {
        root->val = 0;
        st.insert(0);
        solve(root);
    }
    
    bool find(int target) {
        if(st.find(target)!=st.end())return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */