class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<long long> prefix(nums.size(),0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        vector<long long> answer;
        for(int i=0;i<queries.size();i++)
        {
            auto index=upper_bound(nums.begin(),nums.end(),queries[i])-nums.begin();
            auto another=lower_bound(nums.begin(),nums.end(),queries[i])-nums.begin();
            cout<<index<<" "<<another<<"\n";
            another--;
            long long ans=0;
            if(another >= 0)
            {
                 ans =  (queries[i] * (another+1)) - prefix[another];

            }
            long long val=0;
         if(index - 1 >= 0)
             val = prefix[nums.size()-1]-prefix[index-1];
        else
            val=prefix[nums.size()-1];
            
            ans+=(val - queries[i]*(nums.size()-index));
            answer.push_back(ans);
          
        }
        return answer;

    }
};