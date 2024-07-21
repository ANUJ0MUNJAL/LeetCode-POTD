class Solution {
public:
    string losingPlayer(int x, int y) {
        bool flag=1;
        while(x >= 1 and y>= 4){
              x-=1;
              y-=4;
              flag=!flag;
        }
        if(!flag) return "Alice";
        else return "Bob";
    }
};