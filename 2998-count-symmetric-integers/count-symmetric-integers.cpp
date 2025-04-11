class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        while(low <= high){
            string temp = to_string(low);
            if(temp.length()%2 == 0){
                int i=0;
                int j = temp.length()-1;
                int a=0,b=0;
                while(i < j){
                    a+=temp[i]-'0';
                    b+= temp[j]-'0';
                    i++;
                    j--;
                }
                if(a == b)count++;
            }
            low++;
        }
        return count;
    }
};