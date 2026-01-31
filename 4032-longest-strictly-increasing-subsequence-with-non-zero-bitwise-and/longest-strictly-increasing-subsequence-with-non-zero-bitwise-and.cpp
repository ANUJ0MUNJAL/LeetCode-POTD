class Solution {
public:
    int solve(vector<int>&arr)
    {
        
        vector<int> temp;
        for(int i=0;i<arr.size();i++)
        {
            if(temp.size() == 0 or arr[i] > temp.back())
            {
                temp.push_back(arr[i]);
            }else{ 
                
                auto itr = lower_bound(temp.begin(),temp.end(),arr[i]) -temp.begin();
                if(itr == arr.size())temp.push_back(arr[i]);
                else
                temp[itr] = arr[i];
            }
        }
        return temp.size();
    }
    int longestSubsequence(vector<int>& nums) {
         vector<int> bits(31,0);

         map<int,vector<int>> mp;
         for(int i=0;i<nums.size();i++)
         {
             int value = nums[i];
             for(int j=0;j<31;j++)
             {
                  int mask = 1 << j;
                  if(value & mask)
                  {
                       mp[j].push_back(nums[i]);
                  }

             }
         }
         int ans = 0;
         for(auto j: mp)
         {
            
             ans = max(ans,solve(j.second));
         }
         
         return ans;
    }
};