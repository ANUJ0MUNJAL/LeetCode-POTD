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
    long long maxi = 0;
    int mod = 1e9 + 7;

    long long solve(TreeNode* root) {
        if (!root) return 0;
        return root->val + solve(root->left) + solve(root->right);
    }

    long long dfs(TreeNode* root, long long total) {
        if (!root) return 0;

        long long left = dfs(root->left, total);
        long long right = dfs(root->right, total);

        long long sum = root->val + left + right;

        maxi = max(maxi, sum * (total - sum));

        return sum;
    }

    int maxProduct(TreeNode* root) {
        long long total = solve(root);
        dfs(root, total);
        return maxi % mod;  
    }
};
