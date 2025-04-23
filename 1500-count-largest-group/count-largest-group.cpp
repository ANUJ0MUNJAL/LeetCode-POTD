class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int> mp;
        int maxi = 0;
        for(int i=1;i<=n;i++){
            
            int val = i;
            int sum = 0;
            while(val){
                   sum += (val % 10);
                   val/=10;
            }
            mp[sum]++;
            maxi = max(maxi,mp[sum]);
        }
        int count = 0;
        for(auto j: mp){
            if(j.second == maxi)count++;
        }
        return count;
    }
};