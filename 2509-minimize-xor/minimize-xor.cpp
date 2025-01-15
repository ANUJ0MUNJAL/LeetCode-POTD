class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ans = 0;
        while(num2)
        {
            ans+=(num2 % 2);
            num2/=2;
        }
        vector<int> bits;
        while(num1)
        {
            bits.push_back(num1 % 2);
            num1/=2;
        }
        int val = 0;
        multiset<int> st;
        for(int i=bits.size()-1;i>=0;i--)
        {
            if(bits[i])
            {
                st.insert(i);
                val |= (1 << i);
                ans--;
            }
            if(ans==0)break;
        }
        
        int i = 0;
        while(i < 31){
           
            int mask = 1 << i;
            if(val & mask)
            {
                i++;
                continue;
            }
            
                if(ans > 0)
                {
                    val|= mask;
                    ans--;
                }
            
            i++;
        }
        return val;
    }
};