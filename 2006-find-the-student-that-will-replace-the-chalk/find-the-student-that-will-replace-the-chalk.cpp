class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(int i=0;i<chalk.size();i++)sum+=chalk[i];
        long long val = 1LL*k / sum;
        k -= val*sum;
        for(int i=0;i<chalk.size();i++)
        {
             if(chalk[i] > k)return i;
             else k-=chalk[i];
        }
        return -1;
    }
};