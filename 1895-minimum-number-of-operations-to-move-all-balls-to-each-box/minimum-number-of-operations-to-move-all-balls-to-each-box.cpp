class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> index;
        for(int i=0;i<boxes.length();i++)
        {
          if(boxes[i] == '1')
            index.push_back(i);
        }

        vector<int> ans;
        for(int i=0;i<boxes.size();i++)
        {
              int count=0;
              for(int j=0;j<index.size();j++)
              {
                   count+=abs(index[j]-i);
              }
              ans.push_back(count);
        }
        return ans;
    }
};