class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
         multiset<int> st1,st2;
         vector<int> ans;
         for(int i=0;i<A.size();i++)
         {
            int val = 0;
            st1.insert(A[i]);
            st2.insert(B[i]);
            if(st2.find(A[i])!=st2.end())
            {
               st2.erase(st2.find(A[i]));
               st1.erase(st1.find(A[i]));
               val++;
            }
            if(st1.find(B[i])!=st1.end())
            {
                st1.erase(st1.find(B[i]));
                st2.erase(st2.find(B[i]));
                val++;
            }
            if(ans.size()==0)ans.push_back(val);
            else ans.push_back(ans.back()+val);
         }
         return ans;
    }
};