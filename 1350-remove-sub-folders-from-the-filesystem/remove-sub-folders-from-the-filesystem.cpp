class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        for(auto j: folder)
        {
    if(ans.empty() or ans.back().compare(0,ans.back().length(),j,0,ans.back().length())!=0 or j[ans.back().length()]!='/')
    {
        ans.push_back(j);
    }
        }
        return ans;
    }
};