class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        bool flag=true;
        
        int val;
        long long pos=1,neg=1;
        int count=0;
        if(nums.size()==1)return nums[nums.size()-1];
        for(int i=0;i<nums.size();i++){
             if(nums[i] > 0){
                

                  if(pos==0){
                      pos=nums[i];
                      continue;
                  }
                  pos*=nums[i];
             }
             if(nums[i] < 0){
                count++;
                 if(flag){
                    val=nums[i];
                    flag=false;
                 }
                 if(neg == 0){
                    neg=nums[i];
                    continue;
                 }
                 neg*=nums[i];
             }
        }
        if(count <= 1){
            long long val=1;
            bool flag=false;
            bool anuj=false;
             for(int i=nums.size()-1;i>=0;i--){
                  if(nums[i] > 0){
                    anuj=true;
                    val*=nums[i];
                  }
                  if(nums[i] == 0){
                     flag=true;
                  }
             }
             if(anuj){
                return pos;
             }else if(flag){
                return 0;
             }
             
        }
        if(neg < 0){
            neg/=val;
        }
      
        return pos*neg;
        
    }
};