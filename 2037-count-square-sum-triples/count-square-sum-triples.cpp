class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    int val = i*i + j*j;
                    if(val == k*k)
                    {
                        if(i != j)
                        count+=2;
                        else count++;
                    }
                }
            }
        }
            return count;
        
    }
};