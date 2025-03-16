class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,set<int>> mp;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].insert(i);
        }

        vector<int> ans;

        for(int i=0;i<queries.size();i++)
        {
            int index = queries[i];
            int value = nums[index];

            set<int> &temp = mp[value];
            if(temp.size()==1)
            {
                ans.push_back(-1);
                continue;
            }
            if(*temp.begin() == index)
            {
                auto itr = temp.lower_bound(index+1);
                int maxi = *itr-index;
             
                int value = nums.size() - *temp.rbegin();
           
                maxi = min(maxi,value+index);
                ans.push_back(maxi);
            }else if(*temp.rbegin() == index)
            {
                auto itr = temp.lower_bound(0);
                int value = nums.size() - index;
                value += *itr;

                int maxi = value;

                auto another = temp.lower_bound(index);
                another--;
                maxi=min(maxi,index-*another);
                ans.push_back(maxi);
            }
            else{
               auto itr = temp.lower_bound(index+1);
               
                int maxi = *itr-index;
              
                auto another = temp.lower_bound(index);
                another--;
                maxi=min(maxi,index-*another);
                ans.push_back(maxi);
               
            }


        }
        return ans;
    }
};