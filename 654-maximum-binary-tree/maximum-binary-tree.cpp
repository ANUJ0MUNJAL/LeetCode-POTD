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
    TreeNode* solve(vector<int> &nums,int left,int right){
        if(left > right)return nullptr;
        if(left == right)
        {
            return new TreeNode(nums[left]);
        }
        int index = 0;
        int maxi = 0;
        for(int i=left;i<=right;i++)
        {
            if(nums[i] > maxi)
            {
                maxi = nums[i];
                index = i;
            }
        }
        TreeNode*root = new TreeNode(maxi);
        root->left = solve(nums,left,index-1);
        root->right = solve(nums,index+1,right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};