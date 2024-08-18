class Solution {
public:
   
    int nthUglyNumber(int n) {
          set<long long> st;
          st.insert(1);
          for(int i=0;i<n-1;i++)
          {
              long long val=*st.begin();
              st.erase(val);
              st.insert(val*2);
              st.insert(val*3);
              st.insert(val*5);
          }
          return *st.begin();
    }
};