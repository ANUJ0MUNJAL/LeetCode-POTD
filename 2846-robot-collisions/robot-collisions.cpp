class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<array<int,3>> arr;
        for(int i=0;i<positions.size();i++){
            arr.push_back({positions[i],healths[i],directions[i]=='L' ? 0 : 1});
        }
        map<int,int> mp;
       
        sort(arr.begin(),arr.end());
         for(int i=0;i<arr.size();i++){
             mp[arr[i][0]]=i;
        }
        stack<int> st;
        vector<int> temp(arr.size());
        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                if(arr[i][2] == 1){
                    st.push(i);
                }else{
                    temp[i]=arr[i][1];
                }
            }else{
                if(arr[i][2] == 1){
                      st.push(i);
                }else{
                     bool flag=false;
                     while(!st.empty() and arr[st.top()][1] <= arr[i][1]){
                        if(arr[i][1] == arr[st.top()][1]){
                         flag=true;
                         st.pop();
                         break;
                        }
                        if(arr[i][1]  > arr[st.top()][1]) arr[i][1]--;
                            st.pop();
                     }
                     if(st.empty()){
                        if(!flag)
                        temp[i]=arr[i][1];
                     }else{
                         if(!flag)
                         arr[st.top()][1]--;
                     }
                }
            }
        }
      vector<int> ans;
      while(!st.empty()){
              temp[st.top()]=arr[st.top()][1];
              st.pop();
      }
      for(int i=0;i<positions.size();i++){
        
         if(temp[mp[positions[i]]]!=0){
            ans.push_back(temp[mp[positions[i]]]);
         }
      }
      return ans;
    }
};