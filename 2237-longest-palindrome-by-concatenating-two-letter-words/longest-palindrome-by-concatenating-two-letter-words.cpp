class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        for(auto j: words)mp[j]++;
        int ans =0;
        bool flag = false;
        set<string>st;
        for(auto j: mp)
        {
            string temp = j.first;
            string a = temp;
            char b= a[0];
            a[0]=a[1];
            a[1]=b;
            if(st.find(a) != st.end())
            {
                 continue;
            }
            int val = min(j.second,mp[a]);

            if(a == temp)
            {
               if(!flag and mp[a] == 1)
               {
                   flag = true;
                   ans += 2;
               }
               else{
                    if(j.second % 2 == 0)
                       ans+=2*j.second;
                    else{
                        ans+=2*(j.second-1);
                        if(!flag)
                        {
                            ans+=2;
                            flag=true;
                        }
                    }
               }
            }else{
                ans += 4*(min(j.second,mp[a]));
            }
            st.insert(temp);
           
        }
        return ans;
    }
};