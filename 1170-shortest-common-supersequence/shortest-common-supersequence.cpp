class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.length()+1,vector<int>(str2.length()+1,0));

        for(int i=1;i<=str1.length();i++)
        {
            for(int j=1;j<=str2.length();j++)
            {
                 if(str1[i-1] == str2[j-1])
                 {
                    dp[i][j]=1+dp[i-1][j-1];
                 }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 }
            }
        }

        int len = dp[str1.length()][str2.length()];
     
        int i = str1.length();
        int j = str2.length();
        string ans = "";
       
        while(i > 0 and j > 0)
        {
            if(str1[i-1] == str2[j-1])
            {
                i--;
                j--;
                ans+=str1[i];
                len--;
            }else if(dp[i-1][j] > dp[i][j-1])
            {
                i--;
            }else{
                j--;
            }
        }
      
        reverse(ans.begin(),ans.end());
        i = 0;
        j = 0;
        int k = 0;
         string answer="";
        while(k < ans.length())
        {
           while(i < str1.length() and str1[i] != ans[k])
           {
               answer+=str1[i];
               i++;
           }
           while(j < str2.length() and str2[j] != ans[k])
           {
                answer+=str2[j];
                j++;
           }

           answer+=ans[k];
           k++;
           i++;
           j++;
        }
        if(i < str1.length())answer+=str1.substr(i);
        if(j < str2.length())answer+=str2.substr(j);
        return answer;
        
    }
};