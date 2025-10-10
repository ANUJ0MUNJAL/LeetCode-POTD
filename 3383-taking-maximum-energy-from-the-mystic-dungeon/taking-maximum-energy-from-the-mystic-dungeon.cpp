class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        
        for(int i=0;i<energy.size();i++){
            if(i-k>=0)
            energy[i]=max(energy[i],energy[i]+energy[i-k]);
            // energy[i]+=energy[i-k];
        }
        int maxi=INT_MIN;
        for(int i=energy.size()-k;i<energy.size();i++){
            maxi=max(maxi,energy[i]);
        }
        return maxi;
    }
};