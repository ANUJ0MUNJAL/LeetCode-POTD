class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<array<int,3>> arr;
        for(int i=0;i<nums1.size();i++){
            arr.push_back({nums1[i],nums2[i],i});
        }
        sort(arr.begin(),arr.end());
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        long long sum = 0;
        vector<long long> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
             ans[arr[i][2]]=sum;
             long long val = sum;
             while(i+1 < nums1.size() and arr[i][0] == arr[i+1][0]){
                 pq.push(arr[i][1]);
                 sum+=arr[i][1];
                 ans[arr[i+1][2]]=val;
                 if(pq.size() > k){
                    sum-=pq.top();
                     pq.pop();
                 }
                 i++;
             }

             sum+=arr[i][1];
             pq.push(arr[i][1]);
             if(pq.size() > k){
                sum-=pq.top();
                pq.pop();
             }
        }
        return ans;
    }
};