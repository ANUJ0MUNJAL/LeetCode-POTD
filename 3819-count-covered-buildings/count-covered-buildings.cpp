class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
         sort(buildings.begin(),buildings.end());
         map<int,set<int>> mp;
         set<int> st;
         map<int,int> left;
         for(int i=0;i<buildings.size();i++){
            if(st.find(buildings[i][1]) != st.end()){
                 left[i] = 1;
            }
            mp[buildings[i][0]].insert(buildings[i][1]);
            st.insert(buildings[i][1]);
         }

         map<int,int> right;
         st.clear();
         for(int i=buildings.size()-1;i>=0;i--){
            if(st.find(buildings[i][1]) != st.end()){
                 right[i] = 1;
            }
            st.insert(buildings[i][1]);
         }
         int count = 0;
         for(int i=0;i<buildings.size();i++){
             if(left[i] && right[i]){
                 auto itr = mp[buildings[i][0]].find(buildings[i][1]);
                 if(itr == mp[buildings[i][0]].begin()){

                 }
                 else if(++itr == mp[buildings[i][0]].end()){

                 }
                 else count++;
                 
             }
         }
         return count;
    }
};