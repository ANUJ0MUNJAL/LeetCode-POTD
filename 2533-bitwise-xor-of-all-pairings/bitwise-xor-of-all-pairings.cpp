class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() % 2 ==0 and nums2.size()%2 == 0)return 0;
        int val =0;
        if(nums1.size() % 2 == 0 and nums2.size() % 2 != 0)
        {
            for(auto j: nums1)val^=j;
            return val;
        }else if(nums1.size() % 2 != 0 and nums2.size()%2==0)
        {
            for(auto j: nums2)val^=j;
            return val;
        }else{
            for(auto j: nums1)val^=j;
            for(auto j: nums2)val^=j;
        }
        return val;
    }
};