class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            int sum=digits[i]+carry;
            digits[i]=sum%10;
            carry=sum/10;
        }
        if(carry==0)
           return digits;
        else{
            ans.push_back(carry);
            for(int i=0;i<digits.size();i++){
                ans.push_back(digits[i]);
            }
            return ans;
        }
        
        
    }
};