class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int maxi = 0;

        vector<int> left;
        int value = 0;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            int val = i+1;
            if(mp[nums[i]] > (val / 2))
            {
                left.push_back(nums[i]);
                value = nums[i];
                maxi=mp[nums[i]];
            }else{
                if(mp[value] > (val/2))
                left.push_back(value);
                else left.push_back(-1);
            }
        }
        vector<int> right;

        mp.clear();
        value = 0;
        maxi = 0;

         for(int i=nums.size()-1;i>=0;i--){
            mp[nums[i]]++;
            int val = nums.size()-i;
            if(mp[nums[i]] > (val/2))
            {
                right.push_back(nums[i]);
                value = nums[i];
                maxi=mp[nums[i]];
            }else{
                if(mp[value] > (val/2))
                right.push_back(value);
                else
                 right.push_back(-1);
            }
        }

        reverse(right.begin(),right.end());

        for(int i=0;i<nums.size()-1;i++){
            if(left[i] == -1 or right[i+1] == -1)continue;
            if(left[i] == right[i+1]){
                return i;
            }
        }
        return -1;

    }
};