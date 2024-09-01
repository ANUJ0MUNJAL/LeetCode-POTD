class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> temp;
        for(int i=0;i<original.size();)
        {
             int val=n;
             vector<int> ans;
             while(val -- )
             {
                if(i >= original.size())return {}; 
                ans.push_back(original[i]);
                i++;
             }
             temp.push_back(ans);
        }
        if(temp.size() == m)return temp;
        return {};
    }
};