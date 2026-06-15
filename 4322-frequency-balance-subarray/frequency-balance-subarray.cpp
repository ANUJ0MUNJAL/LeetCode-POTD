class Solution {
public:
    int getLength(vector<int>& nums) {
        int ans = 1;
        for(int i=0;i<nums.size();i++)
        {
            map<int,int> mp;
            vector<int> freq(nums.size()+1,0);
            int maxi = 0;
            int total = 0;
            for(int j=i;j<nums.size();j++)
            {
                if(mp[nums[j]])
                {
                    freq[mp[nums[j]]]--;
                }
                mp[nums[j]]++;
                freq[mp[nums[j]]]++;
                if(mp[nums[j]] > maxi)
                {
                    maxi = mp[nums[j]];
                    total = 1;
                }else if(mp[nums[j]] == maxi)
                {
                    total++;
                }

                int count = mp.size();
                if(count == 1)
                {
                     ans = max(ans,j-i+1);
                }else if(maxi%2 == 0 && total < count and freq[maxi/2] == count-total)
                {
                    ans = max(ans,j-i+1);
                }


            }
        }
return ans;
    }
};