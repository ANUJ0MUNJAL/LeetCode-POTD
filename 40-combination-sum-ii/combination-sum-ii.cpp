

class Solution {
public:
    void solve(vector<int>&candidates,int target,int index,vector<vector<int>>&ans,vector<int>&uttar){
        if(target==0){
            ans.push_back(uttar);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
            uttar.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,ans,uttar);
            uttar.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         sort(candidates.begin(),candidates.end());
         vector<vector<int>> ans;
         vector<int>uttar;
         solve(candidates,target,0,ans,uttar);
         return ans;
    }
};
