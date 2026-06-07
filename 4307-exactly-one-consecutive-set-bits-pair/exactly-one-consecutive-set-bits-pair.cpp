class Solution {
public:
    bool consecutiveSetBits(int n) {
        int value = n;
        string temp = "";
        while(value)
        {
           temp += to_string(value % 2);
           value /= 2;
        }
        int count = 0;
        for(int i=1;i<temp.length();i++)
        {
            if(temp[i] == '1' and temp[i-1] == temp[i])
            {
                count++;
            }
        }
        return count == 1;
    }
};