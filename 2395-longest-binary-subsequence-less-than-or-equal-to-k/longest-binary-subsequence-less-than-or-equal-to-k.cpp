class Solution {
public:
    
    int longestSubsequence(string s, int k) {
        int count = 0;
        for(auto j: s)if(j == '0')count++;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i] == '1')
            {
                int index = s.length()-i-1;
                if(index > 30)continue;
                int value = pow(2,index);
                if(value <= k){
                    k-=value;
                    count++;
                }
            }
        }
        return count;
    }
};