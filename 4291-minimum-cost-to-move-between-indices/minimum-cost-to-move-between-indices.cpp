class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> closest(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(i == 0)
            {
               closest[i] = 1;
            }else if(i == nums.size()-1)
            {
                closest[i] = nums.size()-2;
            }else{
                int first = abs(nums[i] - nums[i-1]);
                int second = abs(nums[i] - nums[i+1]);

                if(first <= second)
                {
                    closest[i] = i-1;
                }else if(second < first)
                {
                    closest[i] = i+1;
                }
            }
        }

        vector<int> left(nums.size(),0);
        vector<int> right(nums.size(),0);
        for(int i=1;i<nums.size();i++)
        {
            if(closest[i-1] == i)
            {
                left[i] = 1;
            }else{
                left[i] = abs(nums[i] - nums[i-1]);
            }
        }

        for(int i=nums.size()-2;i>=0;i--)
        {
            if(closest[i+1] == i)
            {
                right[i] = 1;
            }else{
                right[i] = abs(nums[i+1] - nums[i]);
            }
        }

        vector<int> prefixleft(nums.size(),0);
        vector<int> prefixright(nums.size(),0);

        for(int i=0;i<left.size();i++)
        {
            if(i == 0)
            {
                prefixleft[i] = left[i];
            }else{
                prefixleft[i] = prefixleft[i-1]+left[i];
            }
        }

        for(int i=right.size()-1;i>=0;i--)
        {
            if(i == right.size()-1)
            {
                prefixright[i] = right[i];
            }else{
                prefixright[i] = prefixright[i+1]+right[i];
            }
        }

        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];

            if(l <= r)
            {
                ans.push_back(prefixleft[r] - prefixleft[l]);
            }else{
                ans.push_back(prefixright[r] - prefixright[l]);
            }

        }

        return ans;



    }
};