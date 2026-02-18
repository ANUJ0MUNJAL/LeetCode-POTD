class Solution {
public:
    bool hasAlternatingBits(int val) {
        int flag = -1;
        while(val)
        {
            if(flag == -1)
            {
                if(val & 1)flag = 1;
                else flag = 0;
            }
      
            if(flag == 1)
            {
                  if(val & 1){}
                  else return false;
            }else{
                if(val & 1)return false;
            }
            val /= 2;
            flag = !flag;

        }
        return true;
    }
};