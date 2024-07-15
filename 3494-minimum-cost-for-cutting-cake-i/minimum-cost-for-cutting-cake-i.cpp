class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.rbegin(),h.rend());
        sort(v.rbegin(),v.rend());
        int counth=1,countv=1;
        int i=0,j=0;
        int ans=0;
        while(i < h.size() and j < v.size()){
            
            if(h[i] >= v[j]){
                  ans+=(countv* h[i]);
                  counth++;
                  i++;
            }else{
                ans+=(counth*v[j]);
                countv++;
                j++;
            }
            
        }
        while(i < h.size()){
            ans+=countv*h[i];
            counth++;
            i++;
        }
        while(j < v.size()){
            ans+=counth*v[j];
            countv++;
            j++;
        }
        return ans;
        
    }
};