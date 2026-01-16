class Solution {
public:
    int mod=1000000007;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        unordered_map<int,bool> mp;
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                   int val=hFences[j]-hFences[i];
                   mp[val]=true;
            }
        }
        
        long long ans=-1;
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                int val=vFences[j]-vFences[i];
                if(mp.find(val)!=mp.end()){
                    ans=max(ans,1LL*val);
                }
            }
        }
        if(ans==-1)
             return -1;
        return (ans*ans)%mod;
    }
};