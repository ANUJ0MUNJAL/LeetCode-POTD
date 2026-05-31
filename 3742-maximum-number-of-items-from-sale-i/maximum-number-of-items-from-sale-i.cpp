class Solution {
public:
    long long dp[1501][1501][2];
    long long solve(vector<vector<int>>&items,int index,int budget,unordered_map<int,vector<int>>&mp,int flag)
    {
        if(index >= items.size() or budget <= 0)return 0;

        if(dp[index][budget][flag] != -1)
        {
            return dp[index][budget][flag];
        }

        long long include = 0;
        if(budget >= items[index][1])
        {
            int value = flag ? mp[index].size() : 0;
            include = 1 + value + max(solve(items,index,budget-items[index][1],mp,0),solve(items,index+1,budget-items[index][1],mp,1));
        }
        long long exclude = solve(items,index+1,budget,mp,1);
        return dp[index][budget][flag] = max(include,exclude);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
         
         unordered_map<int,vector<int>> mp;
         memset(dp,-1,sizeof(dp));
        
         for(int i=0;i<items.size();i++)
         {
             int value =items[i][0];

             for(int j=0;j<items.size();j++)
             {
                if(i == j)continue;
                int temp = items[j][0] / value;
                if(items[j][0] % value == 0 and value * temp == items[j][0])
                {
                    mp[i].push_back(j);
                }
             }
         }

         return solve(items,0,budget,mp,1);

    }
};