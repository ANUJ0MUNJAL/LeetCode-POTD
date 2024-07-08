class Solution {
public:
    int findTheWinner(int n, int k) {
        set<int> st;
         for(int i=1;i<=n;i++){
            st.insert(i);
         }
         auto start=st.begin();
         while(st.size()>1){
              auto itr=start;
              cout<<*start<<"\n";
              int val=k;
              while(--val){
                  itr++;
                  if(itr==st.end()){
                     itr=st.begin();
                  }
              }
               start=itr;
              start++;
              if(start == st.end()){
                  start=st.begin();
              }
            //   cout<<*itr<<" "<<*start<<"\n";
              st.erase(itr);    
         }
         return *st.begin();
    }
};

