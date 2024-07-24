class Solution {
public:
    bool poss(int mid,string &s,string &p,vector<int>&removable){
         set<int> st;
         for(int i=0;i<mid;i++){
            st.insert(removable[i]);
         }
         string temp="";
         for(int i=0;i<s.length();i++){
             if(st.find(i)==st.end()){
                 temp+=s[i];
             }
         }
         int k=p.length()-1;
         for(int i=temp.length()-1;i>=0;i--){
                 if(p[k] == temp[i]){
                     k--;
                     if(k < 0 )return true;
                 }
         }
         if(k < 0)return true;
         return false;

    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int start=0;
        int end=removable.size();
        int ans=-1;
        while(start <= end){
             int mid=start+(end-start)/2;
             if(poss(mid,s,p,removable)){
                 ans=mid;
                 start=mid+1;
             }else{
                end=mid-1;
             }
        }
        return ans;

    }
};