class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> ans;
        int score = 0;
        int count = 0;
        for(auto j: events)
        {
           if(j == "0" or j =="1" or j=="2" or j=="3" or j=="5" or j=="4" or j=="6")
           {
             score+=stoi(j);
           }
           else if(j == "W")count++;
           else if(j=="WD" or j=="NB")score++;
           if(count == 10)
           {
            return {score,count};
           }
        
        
        }
        return {score,count};
    }
};