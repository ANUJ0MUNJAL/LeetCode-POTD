class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> arr;
        string temp="";
        for(int i=0;i<sentence.length();i++)
        {
             if(sentence[i] == ' ')
             {
                  arr.push_back(temp);
                  temp="";
             }else{
                temp+=sentence[i];
             }
        }
        arr.push_back(temp);
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i][0] != arr[i-1][arr[i-1].length()-1])return false;
        }
        if(arr[0][0] != arr[arr.size()-1][arr[arr.size()-1].length()-1])return false;
        return true;
    }
};