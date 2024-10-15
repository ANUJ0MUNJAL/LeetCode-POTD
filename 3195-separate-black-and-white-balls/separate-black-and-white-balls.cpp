class Solution {
public:
    long long minimumSteps(string s) {
        
        int j=0;
       long long int count=0; 
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                swap(s[i],s[j]);
              
                if(i!=j){
                    count+=i-j;
                }
                  j++;
            }
        }
        return count;
        
    }
};