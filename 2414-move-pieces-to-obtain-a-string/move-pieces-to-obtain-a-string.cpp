class Solution {
public:
    bool canChange(string start, string target) {
        int i=0;
        int j=0;
        while(i < start.length() or j < target.length())
        {
              while(i < start.length() and start[i]=='_')i++;
              while(j < target.length() and target[j] == '_')j++;
              if(i >= start.length() or j >= target.length() or start[i] != target[j] or (start[i]=='L' and i < j) or (target[j]=='R' and i > j))break;
            //   cout<<i<<" "<<j<<endl;
              i++;
              j++;
              
        }
        // cout<<i<<" "<<j<<endl;
        return (i >= start.length() and j >= target.length());
    }
};