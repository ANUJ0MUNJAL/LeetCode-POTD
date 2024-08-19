class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(auto j: tasks)
        {
            mp[j]++;
        }
        int count=0;
        for(auto &j: mp)
        {
           if(j.second < 2)return -1;

           if(j.second % 3 ==1)
           {
                int val=(j.second/3)-1;
                count+=val;
                j.second-=3*val;
                count+=j.second/2;
           }else{
                if(j.second % 3 == 2)
                {
                      count+=j.second/3;
                      count++;
                }else{
                    count+=j.second/3;
                }
           }

        }
        return count;
    }
};