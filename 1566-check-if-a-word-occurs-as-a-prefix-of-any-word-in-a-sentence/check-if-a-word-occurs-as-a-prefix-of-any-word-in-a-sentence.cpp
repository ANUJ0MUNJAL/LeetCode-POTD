class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string temp="";
        int count=0;
        for(int i=0;i<sentence.length();i++)
        {
            if(sentence[i] == ' ')
            {
                if(temp.length() >= searchWord.length() and temp.substr(0,searchWord.length())==searchWord)return count+1;
                temp="";
                count++;
            }else{
                temp+=sentence[i];
            }

        }
      if(temp.length() >= searchWord.length() and temp.substr(0,searchWord.length())==searchWord)return count+1;
        return -1;
    }
};