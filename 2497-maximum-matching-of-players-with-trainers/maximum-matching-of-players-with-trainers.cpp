class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        multiset<int> st(trainers.begin(),trainers.end());
        sort(players.begin(),players.end());
        int count = 0;
        for(int i=0;i<players.size();i++)
        {
            auto itr = st.lower_bound(players[i]);
            if(itr != st.end())
            {
                st.erase(st.find(*itr));
                count++;
            }else{
                return count;
            }
        }
        return count;
    }
};