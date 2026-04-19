class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        reverse(nums2.begin(),nums2.end());
        int ans = 0;
        for(int i=0;i<nums1.size();i++)
        {
            auto itr = lower_bound(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
            if(itr == nums2.size())continue;
            else{
                int val = (int)(nums2.size()-itr-1) - i;
                ans = max(ans,val);
            }
        }
        return ans;
    }
};