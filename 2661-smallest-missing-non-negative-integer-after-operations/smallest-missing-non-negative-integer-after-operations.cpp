class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int> mp;
        for(auto j: nums)
        {
            if(j >= 0)
            {
                mp[j % value]++;
            }else{
            int val = abs(j);
            int q = (val + value - 1) / value;
            int temp = value*q;
            temp-=val;
            mp[temp]++;
            }
        }

        int start = 0;
        while(true)
        {
            if(mp.find(start % value) != mp.end())
            {
                mp[start%value]--;
                if(mp[start%value] == 0)mp.erase(start%value);
                start++;
            }
            else{
                return start;

            }
        }
        return -1;
    }
};