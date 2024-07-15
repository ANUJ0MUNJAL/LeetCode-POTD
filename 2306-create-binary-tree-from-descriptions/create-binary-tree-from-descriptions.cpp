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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int> st;
        map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<descriptions.size();i++){
            st.insert(descriptions[i][1]);
            mp[descriptions[i][0]].push_back({descriptions[i][1],descriptions[i][2]});
        }
        int value;
        for(int i=0;i<descriptions.size();i++){
             if(st.find(descriptions[i][0]) == st.end()){
                    value=descriptions[i][0];
                    break;
             }
        }

        TreeNode* root=new TreeNode(value);
        TreeNode* temp=root;
        queue<TreeNode*> q;
        q.push(temp);

        while(!q.empty()){

            auto el=q.front();
            q.pop();

            for(auto &j: mp[el->val]){
                if(j.second==1){
                  el->left=new TreeNode(j.first);
                  q.push(el->left);
                }else{
                   el->right=new TreeNode(j.first);
                   q.push(el->right);
                }
            }

        }
        return root;

    }
};