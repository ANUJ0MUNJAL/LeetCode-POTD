class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,vector<int>> mp;
        vector<int> dp(nums.size(),1);
        vector<int> prev(nums.size(),-1);
        int lastindex=0;
        int maxlen=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j]+1){
                        dp[i]=max(dp[i],dp[j]+1);
                        prev[i]=j;
                    }
                    if(dp[i] > maxlen){
                        maxlen=dp[i];
                        lastindex=i;
                    }
                }
            }
        }
        vector<int> temp;
        while(lastindex!=-1){
              temp.push_back(nums[lastindex]);
              lastindex=prev[lastindex];
        }
        return temp;
        
    }
};