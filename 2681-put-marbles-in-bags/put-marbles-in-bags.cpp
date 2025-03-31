class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k==1 || weights.size()==k)
          return 0;
        long long ans=0;
        vector<int> temp;
        for(int i=0;i<weights.size()-1;i++){
          temp.push_back(weights[i]+weights[i+1]);
        }
        sort(temp.begin(),temp.end());
        long long mini=0,maxi=0;
        for(int i=0;i<k-1;i++){
            mini+=temp[i];
            maxi+=temp[weights.size()-2-i];
        }
        return maxi-mini;
    }
};