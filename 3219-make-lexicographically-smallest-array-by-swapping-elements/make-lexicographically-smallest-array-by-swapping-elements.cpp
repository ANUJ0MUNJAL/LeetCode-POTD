class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back({nums[i],i});
        }
        sort(ans.begin(),ans.end());
        map<int,vector<pair<int,int>>> mp;
        int val=-1;
        for(int i=0;i<ans.size();i++){
            if(i==0 || ans[i].first-ans[i-1].first>limit)
              val++;
            mp[val].push_back(ans[i]);
        }
        for(auto j: mp){
            vector<int> element,id;
            for(auto i: mp[j.first]){
                element.push_back(i.first);
                id.push_back(i.second);
            }

            sort(id.begin(),id.end());

            for(int i=0;i<id.size();i++){
                nums[id[i]]=element[i];
            }

        }
        return nums;
    }
};