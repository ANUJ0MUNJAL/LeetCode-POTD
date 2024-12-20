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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count=0;
        vector<TreeNode*> temp;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> v;
            while(size--)
            {
                if(count % 2 == 0)
                {
                     temp.push_back(q.front());
                }
                auto el = q.front();
                q.pop();

                if(el->left)q.push(el->left);
                if(el->right)q.push(el->right);
                if(el->left and count % 2 == 0)v.push_back(el->left->val);
                if(el->right and count %2 == 0)v.push_back(el->right->val);
            }
           
            count++;
            reverse(v.begin(),v.end());
            int k=0;
           
            if(v.size()!=0)
            {
                for(auto &j: temp)
                {
                    // cout<<j->val<<endl;
                    j->left->val=v[k];
                    k++;
                    j->right->val=v[k];
                    k++;
                }
                temp.clear();
         
            }

        }
        return root;
    }
};