class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arr, int w, int m) {
        map<int,int> mp;
        int count = 0;
        int slow = 0;
        set<int> st;
        for(int i=0;i<arr.size();i++)
        {
              mp[arr[i]]++;
            
            while(slow <= i and i - slow + 1 > w)
            {
                st.erase(arr[i]);
                mp[arr[slow]]--;
                if(mp[arr[slow]] == 0)
                {
                    mp.erase(arr[slow]);
                }
                slow++;
            }
          
            if((slow <= i and mp[arr[i]] > m))
            {
                count++;
                mp[arr[i]]--;
                arr[i] = 0;
            }
        }
        return count;
    }
};