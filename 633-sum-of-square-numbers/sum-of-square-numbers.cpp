class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for(long long i=0;i*i<=c;i++){
            long long val=c-i*i;
            
            long long another = sqrt(val);

            if(another * another == val){
                return true;
            }

        }
        return false;
    }
    
};