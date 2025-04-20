class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        vector<int> visited(values.size(),false);
        long long ans = 0;
        for(int i=0;i<instructions.size();){
            if(visited[i])return ans;
            if(instructions[i] == "add"){
                ans+=values[i];
                visited[i]=1;
                i++;
            }else{
                visited[i]=1;
                i+=values[i];
                if(i >= values.size() or i < 0)return ans;

            }
          
        }
        return ans;
    }
};