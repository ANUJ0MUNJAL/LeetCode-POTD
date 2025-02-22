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
   int index =1;
    void solve(TreeNode* root,vector<int>&ans,int prevDepth)
    {
        if(index >= ans.size())return;
            cout<<ans[index]<<" "<<prevDepth<<endl;
            if(ans[index] > prevDepth)
            {
                
                root->left = new TreeNode(ans[index+1]);
           
                int val = ans[index];
                index+=2;
                solve(root->left,ans,val);
            if(ans[index] == prevDepth+1){
                root->right = new TreeNode(ans[index+1]);
                index+=2;
                solve(root->right,ans,val);
               }

            }else{
               if(ans[index] == prevDepth+1){
                root->right = new TreeNode(ans[index+1]);
                int val = ans[index];
                index+=2;
                solve(root->right,ans,val);
               }
            }

           
        
    }
    TreeNode* recoverFromPreorder(string traversal) {
        vector<int> ans;
        string temp="";
        for(int i=0;i<traversal.length();i++)
        {
            if(traversal[i] != '-')
            {
                temp+=traversal[i];
            }else{
               
                ans.push_back(stoi(temp));
                temp="";
                int count = 0;
                while(i < traversal.length() and traversal[i] == '-')
                {
                    count++;
                    i++;
                }
                i--;
                ans.push_back(count);
            }
        }
        ans.push_back(stoi(temp));
        TreeNode * root = new TreeNode(ans[0]);
        solve(root,ans,0);
        return root;
    }
};