class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        mean=mean*(rolls.size()+n);
        mean-=accumulate(rolls.begin(),rolls.end(),0);
        if(mean > n*6 || mean < 0 || mean < n)return {};
        
        vector<int> ans;
        int val = mean / n;
        int an = mean % n;
        for(int i=0;i<n;i++)ans.push_back(val);
        int i=0;
        while(an -- )
        {
             ans[i]++;
             i++;
           
        }
        return ans;
    }
};
