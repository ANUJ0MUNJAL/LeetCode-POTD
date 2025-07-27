class Solution {
public:
    long long numOfSubsequences(string s) {
         vector<long long> left(s.length(),0),right(s.length(),0);
         
         for(int i=0;i<s.length();i++)
         {
            if(i == 0)
            {
                if(s[i] == 'L')left[i]++;
            }else{
                left[i] += left[i-1];
                if(s[i] == 'L')left[i]++;
            }
         }

         for(int i=s.length()-1;i>=0;i--)
         {
            if(i == s.length()-1)
            {
                if(s[i] == 'T')right[i]++;
            }else{
                right[i] += right[i+1];
                if(s[i] == 'T')right[i]++;
            }
         }
     
         long long a=0,b=0,c=0;
         long long maxi = 0;
         for(int i=0;i<s.length();i++)
         {
            if(s[i] == 'C')
            {
                a += (left[i]+1)*(right[i]);
                b += ((right[i]+1)*left[i]);
                c+=(left[i]*right[i]);
                
            }
            maxi = max(maxi,left[i]*right[i]);
         }
         return max({a,b,c+maxi});
    }
};