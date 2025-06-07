class Solution {
public:
    string clearStars(string s) {
        vector<set<int>> freq(26);
        vector<bool> visited(s.length(),false);
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                visited[i]=true;
                for(int i=0;i<26;i++){
                    if(freq[i].size()!=0){
                        auto itr=freq[i].rbegin();
                        visited[*itr]=true;
                        freq[i].erase(freq[i].find(*itr));
                        break;
                    }
                }
                
            }else{
                freq[s[i]-'a'].insert(i);
            }
        }
        string temp="";
        for(int i=0;i<s.length();i++){
            if(!visited[i]){
                temp+=s[i];
            }
        }
        return temp;
        
    }
};