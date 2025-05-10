class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long a = accumulate(nums1.begin(),nums1.end(),0LL);
        long long b = accumulate(nums2.begin(),nums2.end(),0LL);
        long long c=0,d=0;
        for(auto j: nums1)if(j == 0)c++;
        for(auto j: nums2)if(j == 0)d++;
         if(c == 0 and d == 0){
            if(a != b)return -1;
        }else if(c == 0){
           if(b+d > a)return -1;
        }else if(d == 0){
            if(a+c > b)return -1;
        }
        long long first = a + c;
        long long second = b + d;

        return max(first,second);

    }
};