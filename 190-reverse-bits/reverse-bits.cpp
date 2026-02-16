class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> arr(32);
        for(int i=0;i<32;i++){
            arr[i]=n&1;
            n=n>>1;
        }
        reverse(arr.begin(),arr.end());
        uint32_t val=0;
        for(int i=0;i<32;i++){
            if(arr[i]==1){
                val+=(1<<i);
            }
        }
        return val;
    }
};