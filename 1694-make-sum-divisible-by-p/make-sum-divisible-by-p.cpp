class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int ans=INT_MAX,total=0;
        for(int i=0;i<nums.size();i++){
                 total=(total+nums[i])%p;
        }
        if(total==0)return 0;
        int prefix=0;
        map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
                 prefix=(prefix+nums[i])%p;

                 int need=(prefix-total+p)%p;

                 if(mp.find(need)!=mp.end()){
                       ans=min(ans,i-mp[need]);
                 }
                 mp[prefix]=i;
        }
        if(ans>=nums.size())return -1;
        return ans;

    }
};