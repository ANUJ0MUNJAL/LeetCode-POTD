class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
          if(s[0]!='0' or s[s.length()-1]!='0')return false;
          vector<int> arr(s.length()+maxJump+2,0);
          int sum=0;
    
          for(int i=0;i<s.length();i++)
          {
            sum+=arr[i];
            if(s[i] == '0' and (i == 0 || sum > 0))
            {
             arr[i+minJump]++;
             arr[i+maxJump+1]--;   
            }       
          }
          if(sum > 0)
          return true;
          return false;
    }
};