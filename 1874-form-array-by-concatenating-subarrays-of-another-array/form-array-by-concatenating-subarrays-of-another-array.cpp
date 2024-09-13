class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        string arr="";
        for(int i=0;i<nums.size();i++)
        {
            string temp = to_string(nums[i]);
            arr+=temp;
            arr+='/';
        }
        vector<string> v;
        for(int i=0;i<groups.size();i++)
        {
             string a="";
             for(auto j: groups[i])
             {
                a+=to_string(j);
                a+='/';
             }
             v.push_back(a);
        }
        cout<<v[0]<<" "<<arr<<"\n";
        int start=0;
        for(int i=0;i<v.size();)
        {
              int val = arr.find(v[i],start);
              
              if(val == -1)return false;
              if(val -1 >=0 and arr[val-1]!='/')
              {
                start=val+v[i].length();
                continue;
              }
              start=val+v[i].length();
              i++;
        }
        return true;
    }
};