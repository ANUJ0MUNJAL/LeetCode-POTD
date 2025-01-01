class Solution {
public:
    int maxScore(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
              if(s[i]=='0')
                 count++;
        }
        int zero=0;
        int maxi=INT_MIN;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0'){
                zero++;
                int length=s.length()-i-1;
                int total=length-count+zero;
                maxi=max(maxi,total+zero);
            }
            else{
                int length=s.length()-i-1;
                int total=length-count+zero;
           
                maxi=max(maxi,total+zero);

            }
        }
        return maxi;
    }
};