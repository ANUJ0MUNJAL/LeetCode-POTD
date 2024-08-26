/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    vector<int> solve(Node* root)
    {
         if(root==NULL)return {};
         vector<int> temp;
         for(auto j: root->children)
         {
              vector<int> child=solve(j);
              for(auto i: child)
              {
                 temp.push_back(i);
              }

         }
         temp.push_back(root->val);
         return temp;
    }
    vector<int> postorder(Node* root) {
        return solve(root);
    }
};