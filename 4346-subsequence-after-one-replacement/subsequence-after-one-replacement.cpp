class Solution {
public:
    bool solve(string &s,string &t)
    {
        //baa 
        //aba
           int j = 0;
        int last = -1;
        for(int i=0;i<t.length();i++)
        {
            if(t[i] == s[j])
            {
                j++;
                last = i;
            }
        }
        cout<<last<<endl;
        if(j >= s.length())return true;

        j++;
        
        if(last+1 >= t.length())return false;
        if(last == -1)last = 0;
        for(int i=last+2;i<t.length();i++)
        {
            if(t[i] == s[j])
            {
                j++;
            }
        }
        return j >= s.length();
    }
    bool canMakeSubsequence(string s, string t) {
     
      string a = s;
      string b = t;

      reverse(s.begin(),s.end());
      reverse(t.begin(),t.end());

      return solve(a,b) || solve(s,t);





        

    }
};