class Solution {
public:
    static bool cmp(int a,int b)
    {
        int val = a;
        int first = 0;
        while(val != 0)
        {
             first+=val%10;
             val/=10;
        }

        int second = 0;
        val = b;
        while(val != 0)
        {
            second+=val%10;
            val/=10;
        }
        if(first == second)
        {
            return a < b;
        }
        return first < second;
    }
    int minSwaps(vector<int>& nums) {
        vector<int> temp(nums.begin(),nums.end());

        sort(nums.begin(),nums.end(),cmp);
        
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
         
            mp[temp[i]]=i;
        }
    
        int count = 0;
        for(int i=0;i<temp.size();i++)
        {
             if(temp[i] == nums[i])continue;
             else{
                int value = mp[nums[i]];

                swap(temp[i],temp[value]);
                mp[temp[value]]=value;
                mp[temp[i]]=i;

                
                count++;
             }
           
             
             cout<<endl;

        }
        return count;

    }
};