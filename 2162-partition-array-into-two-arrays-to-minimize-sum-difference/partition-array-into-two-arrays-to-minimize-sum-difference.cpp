class Solution {
public: 
    int anuj=0;
   
    int minimumDifference(vector<int>& nums) {
        
        for(auto &j : nums){
             anuj+=j;
        }
        vector<set<int>> arr(nums.size()/2+1);
        int value = (1 <<nums.size()/2);
        for(int mask = 0 ; mask < value  ; mask++){
                

              int val= mask;
              int index =0;
              int sum=0;
              
              while(val != 0){
                   if(val & 1){
                        sum+=nums[index];
                   }
                   index++;
                   val=val/2;
              }
              
              int count = __builtin_popcount(mask);

              arr[count].insert(sum);

        }
        int cnt=0;
   
        int mini=INT_MAX;

      
        for(int mask = 0 ; mask < (1 << nums.size()/2) ; mask++){
                

              int val= mask;
              int index =nums.size()/2;
              int sum=0;
              while(val != 0){
                   if(val & 1){
                        sum+=nums[index];
                   }
                   index++;
                   val=val/2;
              }
              

              int count = __builtin_popcount(mask);
              
              int total = anuj/2 - sum;

              auto itr = arr[nums.size()/2 - count].upper_bound(total);
              if(itr != arr[nums.size()/2 - count].end()){
                  int val=*itr;
                  mini=min(mini,abs(anuj - 2*(val+sum)));
              }

              if(itr != arr[nums.size()/2 - count].begin()){
                        itr --;
                   int val=*itr;
                   mini=min(mini,abs(anuj - 2*(val+sum)));
              }
           
        }
        return mini;

        
    } 
};