class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        for(auto j: edges)
        {
            indegree[j[1]]++;
        }
        int mini=n;
        for(auto j: indegree)mini=min(mini,j);
        int ans,count=0;
      
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == mini)
             {
                 count++;
                 ans=i;
             }

        }
        return count == 1 ? ans : -1;
        
    }
};