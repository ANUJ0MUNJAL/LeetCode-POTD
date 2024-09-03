class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp;
        int start=0;
        int ans=0;
        for(int i=0;i<fruits.size();i++)
        {
             mp[fruits[i]]++;

             while(start < i and mp.size() > 2)
             {
                 mp[fruits[start]]--;
                 if(mp[fruits[start]] == 0)
                 {
                     mp.erase(fruits[start]);
                 }
                 start++;
             }
             ans=max(ans,i-start+1);
        }
        return ans;
    }
};