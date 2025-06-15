class Solution {
public:
    int maxDiff(int num) {
        vector<int> dig(10,0);
        string temp = to_string(num);
        int start = -1;
        string a="",b="";
        bool flag=true;
        for(int i=0;i<temp.length();i++)
        {
            if(start == -1 and temp[i]-'0' != 1 and temp[i]-'0'!= 0)
            {
                start = temp[i]-'0';
            }
            if(temp[i]-'0' == start)
            {
                if(i!=0 and flag)
                {
                    b+='0';
                }else{
                  b+='1';
                  flag=false;
                }
            }else{
                b+=temp[i];
            }
            
        }
        cout<<b<<endl;
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