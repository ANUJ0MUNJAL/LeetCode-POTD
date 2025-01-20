class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,int> mp;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                mp[mat[i][j]]=i;
            }
        }
        int ans = arr.size();
        map<int,int> temp;
        for(int i=0;i<arr.size();i++)
        {
            temp[mp[arr[i]]]++;
            if(temp[mp[arr[i]]] == mat[0].size())
            {
                ans = min(ans,i);
                break;
            }
        }


        mp.clear();
        temp.clear();
        for(int i=0;i<mat[0].size();i++)
        {
            for(int j=0;j<mat.size();j++)
            {
                mp[mat[j][i]]=i;
            }
        }
        
        for(int i=0;i<arr.size();i++)
        {
            temp[mp[arr[i]]]++;
            if(temp[mp[arr[i]]] == mat.size())
            {
                ans = min(ans,i);
                break;
            }
        }
        return ans;



    }
};