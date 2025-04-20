class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        int count=0;
        for(int i=0;i<answers.size();i++){
           if(answers[i]==0)
             count++;
           else{
              if(mp[answers[i]]==0)
                count+=answers[i]+1;
               mp[answers[i]]++;
               if(mp[answers[i]]==answers[i]+1){
                   mp[answers[i]]=0;
               }
           }
       
        }
        return count;
    }
};