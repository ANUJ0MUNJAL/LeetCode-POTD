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
    string ans="";
     void inorder(TreeNode* temp,int final,string &a){
        if(temp==NULL)return;
        if(temp->val==final){
            ans=a;
            return;
        }
        a.push_back('L');
        inorder(temp->left,final,a);
        a.pop_back();
        a.push_back('R');
        inorder(temp->right,final,a);
        a.pop_back();
     }
     int val=0;
     void dfs(TreeNode* temp,int dest,int count){
        if(temp==NULL)return;
        if(temp->val==dest){
            val=count;
            return;
        }
        dfs(temp->left,dest,count+1);
        dfs(temp->right,dest,count+1);
     }
     TreeNode* solve(TreeNode *root,int p, int q){
        if(root==NULL or root->val==p or root->val==q)
           return root;
        
        TreeNode* left=solve(root->left,p,q);
        TreeNode* right=solve(root->right,p,q);

        if(left && right){
            return root;
        }

        return left?left:right;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* temp=solve(root,startValue,destValue);
        int value=temp->val;
        string a="";
        inorder(temp,destValue,a);
        // int count=0;
        dfs(temp,startValue,0);
        string uttar="";
        for(int i=0;i<val;i++){
            uttar+='U';
        }
        uttar+=ans;
        return uttar;
    }
};