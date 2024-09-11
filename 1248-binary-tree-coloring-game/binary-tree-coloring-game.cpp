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
    TreeNode* temp;
    void dfs(TreeNode* root,int &count,int x)
    {
        if(root == nullptr)return;
        count++;
        if(root->val == x)temp=root;
        dfs(root->left,count,x);
        dfs(root->right,count,x);
    }
    

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int count=0;
        dfs(root,count,x);
        int left=0,right=0;
         dfs(temp->left,left,x);
         dfs(temp->right,right,x);
   
         vector<int> arr;
         arr.push_back(count-left-right-1);
         arr.push_back(left);
         arr.push_back(right);
         sort(arr.begin(),arr.end());
         if(root->val == x)
         {
            if(left ==right)return false;
            return true;
         }
         cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";
         if(arr[2]-1 > arr[0]+arr[1])return true;
         return false;
        
    }
};