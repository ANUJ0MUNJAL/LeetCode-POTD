class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
         long long ans = 0;

         for(int i = 0 ; i < s.length() ; i++ )
         {
             if(s[i] == t[i])continue;
             else{
                   int a = s[i]-'a';
                   int b = t[i]-'a';
                   int c = s[i]-'a';
                   long long first=0,second=0;

                   while(a != b)
                   {
                      first+=nextCost[a];
                      a++;
                      if(a == 26)a=0;
                   }

                   while(c != b)
                   {
                       second+=previousCost[c];
                       c--;
                       if(c < 0)c=25;
                   }

                   ans+=min(first,second);

             }
         }
         return ans;
    }
};