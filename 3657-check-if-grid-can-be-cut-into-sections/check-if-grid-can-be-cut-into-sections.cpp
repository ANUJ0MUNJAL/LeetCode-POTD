class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> a,b;
        for(int i=0;i<rectangles.size();i++)
        {
            a.push_back({rectangles[i][0],rectangles[i][2]});
            b.push_back({rectangles[i][1],rectangles[i][3]});
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int ans = 0;

        int start = b[0].first;
        int end = b[0].second;
        int i=1;
        while(i < b.size())
        {
            if(b[i].first < end)
            {
                 end = max(end,b[i].second);
            }else{
                ans++;
                start=b[i].first;
                end=b[i].second;
            }
            i++;
        }
        if(ans >= 2)return true;
        start= a[0].first;
        end = a[0].second;
         i=1;
        ans=0;
         while(i < a.size())
        {
            if(a[i].first < end)
            {
                 end = max(end,a[i].second);
            }else{
                ans++;
                start=a[i].first;
                end=a[i].second;
            }
            i++;
        }
        return ans >= 2;
    }
};