class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int start=0;
        int prevsum=0;
        for(int i=0;i<gas.size();i++)
        {
            if(total+gas[i] < cost[i])
            {
                start=i+1;
                prevsum+=(gas[i]-cost[i]);
                prevsum+=total;
                total=0;
            }else{
                total+=(gas[i]-cost[i]);
                
            }
        }
       
        if(total + prevsum >= 0)return start;
        return -1;
    }
};