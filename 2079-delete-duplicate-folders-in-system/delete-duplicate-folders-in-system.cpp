class Solution {
public:
    struct Node{
        string val;
        string subfolder;
        unordered_map<string,Node*> children;
    };
    Node* getNode(string name)
    {
        Node * temp = new Node();
        temp->val = name;
        temp->subfolder="";
        return temp;

    }
    void insert(Node *root,vector<string>&path)
    {
        for(auto j: path)
        {
            if(!root->children.count(j))
            {
                root->children[j] = getNode(j);
            }
            root = root->children[j];
        }
    }

    string findSubFolder(Node* root,unordered_map<string,int>&mp)
    {
        vector<pair<string,string>> subpaths;
        for(auto [name,child] : root->children)
        {
             string temp = findSubFolder(child,mp);
             subpaths.push_back({name,temp});

        }
        sort(subpaths.begin(),subpaths.end());

        string complete = "";

        for(auto&[childname,childpath]: subpaths)
        {
            complete += "(";
            complete+=childname;
            complete+=childpath;
            complete+=")";
        }
        root->subfolder = complete;
        if(complete.length() != 0)mp[complete]++;
        return complete;
    }

    void remove(Node *root,unordered_map<string,int> &mp)
    {
        for(auto it = root->children.begin();it!=root->children.end();)
        {
            Node* child = it->second;
            if(child->subfolder.length() != 0 and mp[child->subfolder] > 1)
            {
                  it = root->children.erase(it);
            }else{
                remove(child,mp);
                it++;
            }
              
        }
    }
    void construct(Node *root,vector<vector<string>> &ans,vector<string>&temp)
    {
        
        for(auto [name,child] : root->children)
        {
             temp.push_back(name);
             ans.push_back(temp);
             construct(child,ans,temp);
             temp.pop_back();
        }
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        
        Node * root = getNode("/");
        for(int i=0;i<paths.size();i++)
        {
            insert(root,paths[i]);
        }
        unordered_map<string,int> mp;
        findSubFolder(root,mp);
        remove(root,mp);
        vector<vector<string>> ans;
        vector<string> temp;
        construct(root,ans,temp);
        return ans;
    }
};