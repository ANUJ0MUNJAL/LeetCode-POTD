class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> prefix;
        for(int i=0;i<nums.size();i++)
        {
            if(i == 0)prefix.push_back(nums[i]);
            else prefix.push_back(prefix.back() ^ nums[i]);
        }
        vector<int> ans;
        for(int i=prefix.size()-1;i>=0;i--)
        {
               int ans1=0;
               for(int j=0;j<maximumBit;j++)
               {
                    int mask = 1<<j;
                    if(mask & prefix[i])
                    {
                        
                    }else{
                          ans1|=mask;
                    }
               }
               ans.push_back(ans1);
        }
        return ans;
    }
};