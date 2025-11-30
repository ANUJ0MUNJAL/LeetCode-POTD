class Solution {
public:
    int reverse(int value)
    {
        string temp = to_string(value);

        int i=0,j=temp.length()-1;
        while(i <= j)
        {
            swap(temp[i++],temp[j--]);
        }
   
        return stoi(temp);
    }
    int minMirrorPairDistance(vector<int>& nums) {
        map<int,int> mp;
        int ans =INT_MAX;
       
        

        for(int i=nums.size()-1;i>=0;i--)
        {
           int val = reverse(nums[i]);
            if(mp.find(val) != mp.end())
            {
                ans = min(ans,mp[val] - i);
            }
            mp[nums[i]] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};