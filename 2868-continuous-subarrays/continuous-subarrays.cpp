class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
         int start=0;
         map<int,int> mp;
         long count=0;
         for(int i=0;i<nums.size();i++)
         {
             mp[nums[i]]++;
             while(start <= i and mp.rbegin()->first - mp.begin()->first > 2)
             {
                   mp[nums[start]]--;
                   if(mp[nums[start]] == 0)
                   {
                       mp.erase(nums[start]);
                   }
                   start++;
             }
             count+=(i-start+1);
         }
         return count;

    }
};