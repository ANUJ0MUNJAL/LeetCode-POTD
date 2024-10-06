class Solution {
public:
    int maxi=INT_MIN;
    void solve(string &temp)
    {
        int ans=0;
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.length();i++)
        {
            int mask = 1<<i;
            int val = temp[i]-'0';
            if(val)
            {
                ans|=mask;
            }
        }
        maxi=max(maxi,ans);
    }
    int maxGoodNumber(vector<int>& nums) {
        vector<string> arr;
        for(int i=0;i<nums.size();i++)
        {
            int val = nums[i];
            string temp="";
            while(val != 0)
            {
                 temp+=to_string(val % 2);
                 val/=2;
            }
            reverse(temp.begin(),temp.end());
            arr.push_back(temp);
        }
        
        string a = arr[2]+arr[0]+arr[1];
        string b = arr[2]+arr[1]+arr[0];
        string c = arr[1]+arr[0]+arr[2];
        string d = arr[1]+arr[2]+arr[0];
        string e = arr[0]+arr[1]+arr[2];
        string f = arr[0]+arr[2]+arr[1];
        
        solve(a);
        solve(b);
        solve(c);
        solve(d);
        solve(e);
        solve(f);
        return maxi;

    }
};