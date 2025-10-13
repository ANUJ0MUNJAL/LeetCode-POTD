class Solution {
public:
    vector<string> removeAnagrams(vector<string>& s) {
        vector<string> ans;
        vector<string> temp = s;
        for(auto &j: s)
        {
            sort(j.begin(),j.end());
        }
        for(int i=0;i<s.size();)
        {
            string temp = s[i];
            while(i< s.size() and s[i] == temp)
            {
                i++;
            }
            ans.push_back(temp);
        }
        vector<string> answer;
        int j = 0;
        for(int i=0;i<temp.size() and j < ans.size();i++)
        {
            string a = temp[i];
            sort(a.begin(),a.end());
          
            if(a == ans[j])
            {
                j++;
                answer.push_back(temp[i]);
            }
        }
        return answer;
    }
};