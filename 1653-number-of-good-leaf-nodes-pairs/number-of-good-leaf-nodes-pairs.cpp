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
    int count=0;
    multiset<int> solve(TreeNode* root,int distance){
        if(root==NULL){
            multiset<int> st;
            return st;
        }
        if(root->left==NULL and root->right==NULL){
            multiset<int> st;
            st.insert(0);
            return st;
        }
        multiset<int> left=solve(root->left,distance);
        multiset<int> right=solve(root->right,distance);
        
        for(auto &j: left){
               for(auto &i: right){
                   if(j+i+2 <= distance)count++;
               }
        }
        multiset<int> temp;
        for(auto &j : left){
            temp.insert(j+1);
        }
        for(auto &i: right){
            temp.insert(i+1);
        }
        return temp;

    }
    int countPairs(TreeNode* root, int distance) {
        solve(root,distance);
        return count;
    }
};