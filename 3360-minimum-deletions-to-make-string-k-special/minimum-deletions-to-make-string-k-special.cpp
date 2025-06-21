class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(auto j: word){
            freq[j-'a']++;
        }
        int mini=INT_MAX;
        for(int i=0; i<= 1e5;i++){
            int ans=0;
            for(auto j: freq){
                if(j<i){
                    ans+=j;
                }
                else if(j > i+k){
                    ans+=j-i-k;
                }
            }
            mini=min(mini,ans);
        }
        return mini;
    }
};