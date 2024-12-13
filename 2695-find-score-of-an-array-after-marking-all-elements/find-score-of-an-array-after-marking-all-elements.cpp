class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int,int>> st;
        for(int i=0;i<nums.size();i++)st.insert({nums[i],i});
        vector<int> vis(nums.size(),false);
        long long ans=0;
        while(!st.empty())
        {
            auto el = st.begin();
            if(vis[el->second])st.erase(el);
            else{
                ans+=el->first;
                if(el->second+1 < nums.size())vis[el->second+1]=1;
                if(el->second-1>=0 )vis[el->second-1]=1;
                st.erase(el);
            }
        }
        return ans;
    }
};