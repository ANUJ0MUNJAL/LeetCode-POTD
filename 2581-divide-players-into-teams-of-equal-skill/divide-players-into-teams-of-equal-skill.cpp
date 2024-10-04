class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0;
        int j=skill.size()-1;
        long long val=skill[i]+skill[j];
        long long ans=0;
        while(i<j){
            if(skill[i]+skill[j]!=val)
                return -1;
            ans+=skill[i]*skill[j];
            i++;
            j--;
        }
        return ans;

    }
};