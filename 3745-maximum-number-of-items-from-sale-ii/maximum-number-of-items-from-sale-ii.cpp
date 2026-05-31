class Solution {
private:
    int solve(int b,vector<vector<int>> &v){
        int n=v.size();
        long long mini=2e9;
        int maxi=0;

        for(auto &x :v){
            mini=min(mini,(long long)x[1]);
            maxi=max(maxi,x[0]);
        }

        vector<int> freq(maxi+1);

        for(auto &x : v){
            freq[x[0]]++;
        }

        vector<long long> mul(maxi+1);

        for(int i=1;i<=maxi;i++){
            if(freq[i]==0){
                continue;
            }

            for(int j=i;j<=maxi;j+=i){
                mul[i]+=freq[j];
            }
        }

        map<long long,long long> mp;

        for(auto &x : v){
            long long p=x[1];
            long long c=mul[x[0]]-1;

            if(c>0 && p < 2*mini){
                mp[p]+=c;
            }
        }

        long long ans=b/mini;
        long long d=0;
        long long rem=b;

        for(auto &it :mp){
            long long p=it.first;
            long long c=it.second;
            long long t=min(c,rem/p);

            if(!t){
                break;
            }

            d+=t;
            rem-=t*p;

            ans=max(ans,2*d+rem/mini);

            if(rem<p){
                break;
            }
        }

        return (int)ans;
    }
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int ans=solve(budget,items);

        return ans;
    }
};