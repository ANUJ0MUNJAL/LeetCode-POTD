class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
       sort(spaces.begin(),spaces.end());
       string ans = "";
       int start=0;
       string val ="";
       for(int i=0;i<spaces.size();i++)
       {
            if(i == 0){
              val = s.substr(start,spaces[i]);
             ans+=val;
             start=spaces[i];
             ans+=' ';
            }else{
                 val = s.substr(start,spaces[i]-spaces[i-1]);
                start=spaces[i];
                ans+=val;
                ans+=' ';
            }
       }
        val = s.substr(spaces[spaces.size()-1]);
       ans+=val;
       return ans;
    }
};