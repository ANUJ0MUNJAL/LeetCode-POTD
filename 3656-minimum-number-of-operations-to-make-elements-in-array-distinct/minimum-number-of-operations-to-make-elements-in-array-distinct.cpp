class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>  mp;
        int i;
        for( i=nums.size()-1;i>=0;i--)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1)break;
        }
        i++;
        return (i+2)/3;
    }
};