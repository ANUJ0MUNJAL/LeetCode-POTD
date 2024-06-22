class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        queue<int> q;
        int gap=-1;
        int ans=0;
        int last=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] % 2)q.push(i);

            if(q.size() > k){
                last=q.front();
                q.pop();
            }
            if(q.size() == k){
                 gap=q.front()-last;
                 ans+=gap;
            }
        }
        return ans;
        
    }
};