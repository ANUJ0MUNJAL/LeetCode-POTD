class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {

       vector<int> t;
        int zero=0,one=0;
        int i =0;
        for(auto j: s)
        {
            if(j == '0')
            {
                t.push_back(i);
                zero++;
            }else{
                one++;
            }
            i++;
        }
        vector<bool> ans;
        for(auto j: strs)
        {
            int q = count(j.begin(),j.end(),'?');
            int a = count(j.begin(),j.end(),'0');

            if(a > zero or a+q < zero)
            {
                ans.push_back(false);
                continue;
            }
            int left = zero - a;

            for(auto &i: j)
            {
                if(i == '?')
                {
                    if(left)i='0',left--;
                    else i = '1';
                }
            }
            vector<int> temp;
            for(int i=0;i<j.length();i++)
            {
                if(j[i] =='0')temp.push_back(i);
            }
            bool flag = true;

            for(int i=0;i<t.size();i++)
            {
                if(t[i] < temp[i])flag=false;
            }
            ans.push_back(flag);

        }
        return ans;
    }
};