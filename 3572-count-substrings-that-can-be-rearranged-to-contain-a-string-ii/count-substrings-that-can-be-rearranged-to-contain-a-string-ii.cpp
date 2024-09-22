class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        long long ans =0;
        
        map<int,int> mp;
        for(auto j: word2)mp[j]++;
        map<int,int> mp1;
        int slow=0;
        for(int i=0;i<word1.size();i++)
        {
            mp1[word1[i]]++;
        
            bool flag=true;
            for(auto j: mp)
            {
                if(j.second > mp1[j.first])
                {
                    flag=false;
                    break;
                }
            }
            while(slow <= i and flag)
            {
                ans+=(word1.length()-i);
                mp1[word1[slow]]--;
                
                if(mp[word1[slow]] > mp1[word1[slow]])
                {
                    slow++;
                    break;
                }
                slow++;
                
            }
        }    
        return ans;
    }
};