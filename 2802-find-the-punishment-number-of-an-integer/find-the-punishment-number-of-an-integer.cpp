class Solution {
public:
    bool solve(int num,string &temp,int index,int sum)
    {
          if(index >= temp.length())
          {
            if(sum == num)return true;
            return false;
          }
          for(int i=index;i<temp.length();i++)
          {
             
             string t = temp.substr(index,i-index+1);
             int val = stoi(t);
             if(val > num)return 0;

             if(solve(num,temp,i+1,sum+val))return true;
              
          }
          return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
             int value = i*i;
             string temp = to_string(value);
            if(solve(i,temp,0,0))ans+=(i*i);
        }
        return ans;
    }
};