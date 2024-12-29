class Solution {
public:
    void find(string &word,char a,vector<int> &index)
    {
        for(int i=0;i<word.length();i++)
        {
            if(word[i] == a)index.push_back(i);
        }
        
    }
    string answerString(string word, int numFriends) {
          if(numFriends == 1)return word;
          for(char i = 'z' ; i >= 'a' ; i--)
          {
                int count = 0;
                if(word.find(i)!=-1)
                {
                    vector<int> arr;
                      find(word,i,arr);
                      set<string> st;
                      for(int j =0;j<arr.size();j++){
                      count = 0;
                      int index = arr[j];

                      count+=index;
      
                      string temp = word.substr(index);
                      string ans = temp;
                     
                      if(count < numFriends)
                         ans = temp.substr(0,temp.length() - numFriends + count + 1);
                         st.insert(ans);
                      }
                     if(st.size()!=0)
                return *st.rbegin();
                }
                
          }
          return "";
    }
};