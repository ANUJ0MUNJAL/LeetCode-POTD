class Solution {
public:
    int minFlips(string s) {
        // all 1 all 0
        int zero = 0;
        int one = 0;
        for(auto j: s)
        {
            if(j == '0')zero++;
            else one++;
        }
    
        int ans = min(zero,one);

        // single 1

        if(one >= 1)
        {
           ans = min(ans,one-1);

           // lets make 100001
           int count = 0;

           for(int i=0;i<s.length();i++)
           {
              if(i == 0 or i == s.length()-1)
              {
                   if(s[i] == '1'){

                   }
                   else count++;
              }else{
                  if(s[i] == '1')count++;
              }
           }
           ans = min(ans,count);
        }
        return ans;
        
    }
};