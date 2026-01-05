class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        map<int,int> mp,mp1;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            mp1[forbidden[i]]++;
        }
        for(auto j: mp)
        {
            if(j.second > nums.size() - mp1[j.first])return -1;
        }
        int count = 0;
        map<int,int> temp;
        int maxi = 0;
        for(int i=0;i<nums.size();i++)
        {
             if(nums[i] == forbidden[i])
             {
                count++;
                temp[nums[i]]++;
                maxi = max(maxi,temp[nums[i]]);
             }
        }
        return max(maxi,(count+1)/2);
    }
};