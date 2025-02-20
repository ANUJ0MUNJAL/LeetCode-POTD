class Solution {
public:
    string uttar="";
    void solve(string ans,map<string,int>&mp,vector<string>&nums){
        if(ans.length()==nums.size()){
            if(uttar.length()==0 && mp.find(ans)==mp.end()){
                uttar=ans;
                return;
            }
            return;
        }
        ans+='0';
        solve(ans,mp,nums);
        ans.pop_back();
        ans+='1';
        solve(ans,mp,nums);
        ans.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        map<string,int> mp;
        for(auto j: nums){
            mp[j]=1;
        }
        solve("",mp,nums);
        return uttar;
    }
};