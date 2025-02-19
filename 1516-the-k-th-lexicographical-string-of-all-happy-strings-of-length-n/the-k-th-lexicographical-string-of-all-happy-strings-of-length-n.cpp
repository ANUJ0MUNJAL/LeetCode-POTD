class Solution {
public:
    vector<string> v;
    void solve(int n,string temp)
    {
        if(temp.length() == n)
        {
           v.push_back(temp);
            return;
        }

        for(char i = 'a' ; i <= 'c' ; i++)
        {
             if(temp.length() == 0)
             {
                
                solve(n,temp+i);
             }else{
                if(temp.back() == i)continue;
                solve(n,temp+i);
             }
        }
    }

    string getHappyString(int n, int k) {
        solve(n,"");
        sort(v.begin(),v.end());
        if(v.size() < k)return "";
        return v[k-1];
    }
};