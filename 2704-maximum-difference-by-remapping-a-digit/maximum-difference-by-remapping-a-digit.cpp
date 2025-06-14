class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> dig(10,0);
        string temp = to_string(num);
        int start = -1;
        string a="",b="";
        for(int i=0;i<temp.length();i++)
        {
            if(start == -1)
            {
                start = temp[i]-'0';
            }
            if(temp[i]-'0' == start)
            {
                b+='0';
            }else{
                b+=temp[i];
            }
            
        }
        start = -1;
        for(int i=0;i<temp.length();i++)
        {
            if(start == -1 and temp[i]-'0' != 9)
            {
                start = temp[i]-'0';
            }
            if(temp[i]-'0' == start)
            {
                a+='9';
            }else{
                a+=temp[i];
            }
        }
        return stoi(a)-stoi(b);
        
       


    }
};