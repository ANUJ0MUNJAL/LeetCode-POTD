class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        map<int,int> mp;
        for(int i=0;i<events.size();i++)
        {
            if(i == 0)
            {
                 mp[events[i][0]]+=events[i][1];
            }else{
                mp[events[i][0]]=max(mp[events[i][0]],(events[i][1]-events[i-1][1]));
            }
        }
        int maxi=0;
        for(auto j: mp)
        {
             maxi=max(maxi,j.second);
        }
        cout<<mp[2]<<" "<<mp[19]<<endl;
        for(auto j: mp)
        {
            if(j.second == maxi)return j.first;
        }
        return -1;

    }
};