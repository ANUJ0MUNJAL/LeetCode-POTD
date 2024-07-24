class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>mp(256,0);
        vector<int>visited(256,0);
        for(int i=0;i<s.length();i++){
             mp[s[i]-'a']++;
        }
        string temp="0";
        for(int i=0;i<s.length();i++){
             mp[s[i]-'a']--;
             if(visited[s[i]-'a'])continue;
             while(temp.length()!=1 and s[i] < temp.back() and mp[temp.back()-'a']){
                   visited[temp.back()-'a']=false;
                   temp.pop_back();
             }
             
             temp+=s[i];
           
             visited[s[i]-'a']=true;
        }
        return temp.substr(1);

       

    }
};