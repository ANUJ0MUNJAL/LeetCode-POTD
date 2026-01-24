class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int,int>> arr;
        vector<int> maxi;
        for(int i=0;i<costs.size();i++)
        {
           arr.push_back({costs[i],capacity[i]});
        }
        sort(arr.begin(),arr.end());
        int ans = 0;
       
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i].first < budget)
            ans = max(ans,arr[i].second);
            if(i == 0)maxi.push_back(arr[i].second);
            else{
                maxi.push_back(max(maxi.back(),arr[i].second));
            }
        }

        for(int i=0;i<arr.size();i++)
        {
            int value = arr[i].second;
            int left = budget - arr[i].first;

            auto itr = lower_bound(arr.begin(),arr.begin()+i,make_pair(left,0))-arr.begin();
          
            itr--;
            if(itr >= 0)
            {
                ans = max(ans,value + maxi[itr]);
            }
        }
        return ans;
        
    }
};