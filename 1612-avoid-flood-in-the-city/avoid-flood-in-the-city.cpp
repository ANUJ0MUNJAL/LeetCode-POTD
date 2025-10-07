class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        map<int,int> mp;
        vector<int> ans(rains.size(),-1);
        int count = 0;
        set<int> st;

        for(int i=0;i<rains.size();i++)
        {
            if(rains[i] == 0)
            {
                st.insert(i);
                count++;
            }
            else{
              
                if(mp.count(rains[i]))
                {

                  
                    if(count > 0)
                    {
                    auto itr = st.upper_bound(mp[rains[i]]);
                    if(itr == st.end())return {};
                 
                    ans[*itr] = rains[i];
                    st.erase(st.find(*itr));
                    mp[rains[i]] = i;
                    count--;   
                    }else
                    return {};
                    
                }else{
                mp[rains[i]] = i;
                 ans[i] = -1;
                }
            }
        }
        while(st.size() > 0)
        {
            ans[*st.begin()] = 1;
            st.erase(st.begin());
        }
        return ans;
    }
};