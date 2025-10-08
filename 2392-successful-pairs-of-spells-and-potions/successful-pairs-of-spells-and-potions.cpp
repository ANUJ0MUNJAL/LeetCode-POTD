class Solution {
public:
    int solve(int value,vector<int>&potions,long long success){
        int i=0;
        int j=potions.size()-1;
        int ans=potions.size();
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(1LL*potions[mid] * value >= success){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;

        sort(potions.begin(),potions.end());

        for(int i=0;i<spells.size();i++){
            int val=solve(spells[i],potions,success);
            cout<<val<<endl;
            ans.push_back(potions.size()-val);
        }
        return ans;

    }
};