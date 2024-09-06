class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        int n=0;
        while(n <= num)
        {
            string temp = to_string(n);
            reverse(temp.begin(),temp.end());
            int val = n+stoi(temp);
            if(val == num)return true; 
            n++;
        }
        return false;
    }
};