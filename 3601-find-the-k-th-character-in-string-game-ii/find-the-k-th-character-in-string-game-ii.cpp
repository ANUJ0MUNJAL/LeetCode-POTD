class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        string temp = "";
        for(int i=0;i<operations.size();i++)
        {
            temp+=to_string(operations[i]);
        }
        string another="";
        k--;
        while(k)
        {
            another+=to_string(k % 2);
            k/=2;
        }
        while(another.length() < temp.length())
        {
            another+='0';
        }
       
        char start = 'a';
        //a ab abab
        for(int i=0;i<operations.size();i++)
        {
            if(another[i] == '1' and temp[i] == '1')
            {
                if(start == 'z')start='a';
                else
                start = start + 1;
            }
        }

        return start;
    }
};