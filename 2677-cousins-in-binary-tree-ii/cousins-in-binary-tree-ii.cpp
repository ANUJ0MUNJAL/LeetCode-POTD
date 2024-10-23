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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
         root->val=0;
        while(!q.empty())
        {
            int size=q.size();
            int sum=0;
            vector<TreeNode*> arr;
            while(size--)
            {
                
                auto node = q.front();
                arr.push_back(node);
                q.pop();
              
                if(node->left)
                {
                    q.push(node->left);
                    sum+=node->left->val;
                }
                if(node->right)
                {
                    q.push(node->right);
                    sum+=node->right->val;
                }
            }
            for(auto node: arr)
            {
                  int total = sum;
                  if(node->left)total-=node->left->val;
                  if(node->right)total-=node->right->val;
                  if(node->left)node->left->val=total;
                  if(node->right)node->right->val=total;
            }
            
        }
        return root;
    }
};