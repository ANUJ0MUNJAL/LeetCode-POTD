class Solution {
public:
    int minDeletionSize(vector<string>& str) {
        int count = 0;
        for(int i=0;i<str[0].length();i++)
        {
            bool flag = false;
            for(int j=1;j<str.size();j++)
            {
                if(str[j][i] < str[j-1][i])
                {
                    flag = true;
                    break;
                }
            }
            if(flag)count++;
        }
        return count;
    }
};