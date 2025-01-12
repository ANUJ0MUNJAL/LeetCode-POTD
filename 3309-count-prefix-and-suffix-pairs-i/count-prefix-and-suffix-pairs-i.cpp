class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(words[i].length() > words[j].length())
                    continue;
                string first=words[j].substr(0,words[i].length());
                string second=words[j].substr(words[j].length()-words[i].length(),words[i].length());
                if(first == second and second==words[i]){
                    count++;
                }
                
            }
        }
        return count;
    }
};