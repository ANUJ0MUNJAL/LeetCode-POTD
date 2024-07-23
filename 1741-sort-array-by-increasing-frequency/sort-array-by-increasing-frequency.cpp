class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
         if(a.second == b.second){
              return a.first > b.first;
         }
         return a.second < b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> arr;
        for(auto &j: mp){
             arr.push_back({j.first,j.second});
        }
        sort(arr.begin(),arr.end(),cmp);

        vector<int> ans;
        for(int i=0;i<arr.size();i++){
               
               for(int j=0;j<arr[i].second;j++){
                ans.push_back(arr[i].first);
               }
        }
        return ans;
    }
};