class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
            map<int,int> mp;
            for(int i=indexDifference;i<nums.size();i++)
            {
                mp[nums[i - indexDifference]] = i - indexDifference;

                auto itr = mp.lower_bound(nums[i] + valueDifference);

                if(itr != end(mp))return{i , itr->second};

                itr = mp.upper_bound(nums[i] -valueDifference);

                if(itr != begin(mp))
                {
                    itr--;
                    return {i,itr->second};
                }

            }
            return {-1,-1};
    }
};