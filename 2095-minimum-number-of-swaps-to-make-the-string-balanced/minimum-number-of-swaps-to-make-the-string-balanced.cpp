class Solution {
public:
    int minSwaps(string s) {
       int open=0;
       int j=s.length()-1;
       int count=0;
       while(j>=0 and s[j]==']')j--;
       for(int i=0;i<s.length();i++){
            if(s[i] == ']' and open == 0){
                   swap(s[i],s[j]);
                   j--;
                  while(j>i and s[j]==']')j--; 
                  count++;
                  open++;
            }else if(s[i] == ']'){
                   open--;
                   
            }else{
                  open++;
            }
       }
       return count;
    }
};