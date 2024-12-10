class Solution {
public:

    int maximumLength(string s) {
        
        for(int i=50;i>=1;i--){
            map<string,int> mp;
            for(int j=0;j<s.length();j++){
                if(j+i<=s.length()){
                string temp=s.substr(j,i);
                
                    bool flag=false;
                    
                for(int k=1;k<temp.length();k++){
                    if(temp[k]!=temp[k-1]){
                        flag=true;
                        break;
                    }
                }  
                    
                 if(flag)
                     continue;
                    
                    
                    
                    
                    
                    
                mp[temp]++;
                if(mp[temp]>=3){
                    return i;
                }
                }else{
                    break;
                }
            }
        }
        return -1;
    }
};