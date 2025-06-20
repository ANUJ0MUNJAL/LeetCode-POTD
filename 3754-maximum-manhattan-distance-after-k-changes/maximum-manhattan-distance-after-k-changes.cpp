class Solution {
public:
    int maxDistance(string s, int k) {
        // N E
        int maxi = INT_MIN;
        int val = k;
        int count = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='N' or s[i]=='E')count++;
            else{
                if(k > 0)
                {
                    count++;
                    k--;
                }else{
                    count--;
                }
            }
            maxi=max(maxi,count);
    
        }
        count = 0;
        k = val;
        // N W
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='N' or s[i]=='W')count++;
            else{
                if(k > 0)
                {
                    count++;
                    k--;
                }else{
                    count--;
                }
            }
            maxi=max(maxi,count);
    
        }
        // S E
        count = 0;
        k = val;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='S' or s[i]=='E')count++;
            else{
                if(k > 0)
                {
                    count++;
                    k--;
                }else{
                    count--;
                }
            }
            maxi=max(maxi,count);
    
        }
        // S W
        k = val;
        count = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='S' or s[i]=='W')count++;
            else{
                if(k > 0)
                {
                    count++;
                    k--;
                }else{
                    count--;
                }
            }
            maxi=max(maxi,count);
    
        }
        return maxi;

    }
};