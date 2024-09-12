class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
         set<char> st;
         for(auto j: allowed)st.insert(j);
         int count=0;
         for(auto j: words)
         {
             set<char> st1;
             for(auto i: j)st1.insert(i);
             bool flag=true;
             for(auto j: st1)
             {
                if(st.find(j) == st.end())
                {
                    flag=false;
                    break;
                }
             }
             if(flag)count++;
         }
         return count;
        
    }
};