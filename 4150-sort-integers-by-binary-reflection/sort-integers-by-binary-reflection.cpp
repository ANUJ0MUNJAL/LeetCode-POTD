class Solution {
public:
    static bool cmp(int a,int b)
    {    
         int value = a;
         string abin = "";
         string bbin = "";
         while(value)
         {
             abin += ((value % 2) + '0');
             value /= 2;
         }
         value = b;
         while(value)
         {
             bbin += ((value % 2) + '0');
             value /= 2;
         }

         
         int adec = std::stoi(abin, nullptr, 2);
         int bdec = std::stoi(bbin, nullptr, 2);
         
   
         if(adec == bdec)return a <= b;
         return adec < bdec;
        
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        return nums;
    }
};