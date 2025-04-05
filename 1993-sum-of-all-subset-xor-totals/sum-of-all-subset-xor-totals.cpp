class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
       
        for(int mask=0;mask < (1 << nums.size()) ; mask++){
              
              int val=mask;
              int total=0;

              for(int i=0;i<31;i++){
                   int check=(1 << i);
                   if((val & check)){
                    
                       total^=nums[nums.size()-i-1];
                   }
              }
        
              sum+=total;
        }
        return sum;
    }
};