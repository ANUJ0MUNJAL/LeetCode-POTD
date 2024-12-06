class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> st(banned.begin(),banned.end());
        int count = 0;
        for(int i=1;i<=n;i++)
        {
            if(st.find(i)!=st.end())continue;
            if(i > maxSum)break;
            maxSum-=i;
            count++;
        }
        return count;
    }
};