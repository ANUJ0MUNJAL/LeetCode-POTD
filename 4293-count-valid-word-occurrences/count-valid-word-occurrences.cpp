class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string temp = "";
        for(auto j: chunks)temp+=j;
        map<string,int> mp;
        string ans = "";
        for(int i=0;i<temp.length();i++)
        {
            if(temp[i] == ' ')
            {
               mp[ans]++;
               ans = "";
            }else if(temp[i] == '-'){
                if(ans.length() != 0 and i+1 < temp.length() and temp[i+1] >='a' and temp[i+1] <='z')ans+='-';
                else{
                    if(ans.length()!=0)
                    {
                        mp[ans]++;
                        ans = "";
                    }
                }
            }
            else{
                ans += temp[i];
            }
        }
    
        mp[ans]++;
        vector<int> ans1;
        for(auto j: queries)
        {
            ans1.push_back(mp[j]);
        }
        return ans1;
    }
};