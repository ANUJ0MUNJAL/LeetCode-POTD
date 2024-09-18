class Solution {
public:
    static bool cmp(string &a,string &b)
    {
        
        string c= a+b;
        string d = b+a;
        if(c > d)return true;
        else return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(auto j: nums)
        {
            temp.push_back(to_string(j));
        }
        sort(temp.begin(),temp.end(),cmp);
        string ans="";
        for(int i=0;i<temp.size();i++)
        {
            
            ans+=temp[i];
        }
        set<char> st;
        for(auto j: ans)st.insert(j);
        
        if(st.size()==1 and *st.begin() == '0')return "0";
        return ans;

    }
};