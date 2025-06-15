class Solution {
public:
    string generateTag(string caption) {
        string ans = "#";
        int i = 0;
        while(i < caption.length() and caption[i]==' ')i++;
        caption = caption.substr(i);
        for(int i=0;i<caption.length();i++)
        {
            
            if((caption[i] >= 'a' and caption[i] <='z') or (caption[i] >='A' and caption[i] <='Z'))
            {

                if(i != 0 and caption[i-1] ==' ')
                {
                     char temp = caption[i];
                     if(temp >= 'A' and temp <='Z')
                     {
                        ans+=temp;
                     }else{
                         ans+=(temp-'a'+'A');
                     }
                }else{

                    char temp = caption[i];
                     if(temp >= 'a' and temp <='z')
                     {
                        ans+=temp;
                     }else{
                         ans+=(temp-'A'+'a');
                     }

                }
               
            }
        }
        string a = ans.substr(0,min(100,(int)ans.length()));
        return a;
    }
};