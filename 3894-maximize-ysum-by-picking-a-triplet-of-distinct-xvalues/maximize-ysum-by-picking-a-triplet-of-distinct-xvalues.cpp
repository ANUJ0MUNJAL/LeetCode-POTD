class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        vector<pair<int,int>> arr;
        for(int i=0;i<x.size();i++)
        {
            arr.push_back({x[i],y[i]});
        }
        vector<int> temp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {
            int maxi = arr[i].second;
            while(i+1 < arr.size() and arr[i].first == arr[i+1].first)
            {
                 maxi = max(maxi,arr[i+1].second);
                 i++;
            }
            temp.push_back(maxi);
        }
        
        if(temp.size() < 3)return -1;
        sort(temp.begin(),temp.end(),greater<int>());
       
        int ans = 0;
        for(int i=0;i<=2;i++)
        {
            ans = ans + temp[i];
        }
        return ans;
    }
};