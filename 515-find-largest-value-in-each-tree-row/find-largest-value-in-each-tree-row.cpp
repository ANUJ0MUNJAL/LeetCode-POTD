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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int size=q.size();
            int maxi=INT_MIN;
            while(size--){
                auto element=q.front();
                q.pop();
                if(element->left){
                    q.push(element->left);
                }
                if(element->right){
                    q.push(element->right);
                }
                maxi=max(maxi,element->val);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};