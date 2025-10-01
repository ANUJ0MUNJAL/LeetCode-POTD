class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int khali=0,ans=0;
         while(numBottles){
             ans+=numBottles;
             khali+=numBottles%numExchange;
             numBottles/=numExchange;
             
             numBottles+=khali/numExchange;
             khali%=numExchange;
              
         }
         return ans;
    }
};