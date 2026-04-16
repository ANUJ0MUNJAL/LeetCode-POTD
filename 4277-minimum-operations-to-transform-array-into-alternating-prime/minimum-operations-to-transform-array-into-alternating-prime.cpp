class Solution {
public:
    void solve(vector<int>& prime)
{
    vector<int> vis(2e5+10, 0);
    for(int i = 2; i <= 2e5; i++)
    {
        if(!vis[i])
        {
            prime.push_back(i);
            for(int j = i * 2; j <= 2e5; j += i)
            {
                vis[j] = 1;
            }
        }
    }
}
    int minOperations(vector<int>& nums) {
        vector<int> prime;
        solve(prime);
       
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(i % 2 == 0)
            {
                auto itr = lower_bound(prime.begin(),prime.end(),nums[i])-prime.begin();
                count += abs(prime[itr]-nums[i]);
            }else{
                auto itr = lower_bound(prime.begin(),prime.end(),nums[i])-prime.begin();
                if(itr == prime.size())continue;
                if(nums[i] != 2 and abs(prime[itr]-nums[i]) == 0)
                {
                    count++;
                }else if(nums[i] == 2)
                {
                    count+=2;
                }
            }
        
            
        }
        return count;
    }
};