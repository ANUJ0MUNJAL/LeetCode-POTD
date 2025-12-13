class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int a =0, b =0;
        vector<int> diff(technique1.size(),-1);
        set<pair<int,int>> st;
        long long ans = 0;
        for(int i=0;i<technique1.size();i++)
        {
            if(technique1[i] < technique2[i])
            {
               diff[i] = abs(technique1[i] - technique2[i]);
               st.insert({diff[i] , i});
               b++;
               ans += technique2[i];
            }else{
               a++;
               ans += technique1[i];
            }
        }
        if(a >= k)return ans;

        for(auto j: st)
        {
            ans -= diff[j.second];
            a++;
            if(a >= k)return ans;
        }
        return ans;


    }
};