class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;

        for(int i=1;i<n;i++)
        {
            string a = to_string(i);
            string b = to_string(n-i);
           bool flag = false;
           for(auto j: a)
           {
            if(j=='0')flag=true;
           }
           for(auto j: b)
           {
            if(j=='0')flag=true;
           }
           if(!flag)return {i,n-i};

        }
        return {};
    }
};