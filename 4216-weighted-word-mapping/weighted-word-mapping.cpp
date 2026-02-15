class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
       
        string ans = "";
        
        for(auto j: words)
        {
            int sum = 0;
            for(auto i: j)
            {
                int value = i - 'a';
                sum += weights[value]; 
           }
         
           sum %= 26;
        
           ans += 'a' + (25-sum);
        }
        return ans;
    }
};