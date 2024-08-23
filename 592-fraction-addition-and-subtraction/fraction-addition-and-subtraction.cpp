class Solution {
public:
    string fractionAddition(string expression) {
        int lcm=0;
        for(int i=0;i<expression.length();i++)
        {
             if(expression[i]=='/')
             {
                  if(lcm == 0)
                  {
                   
                     lcm=expression[i+1]-'0';
                if(i+2 < expression.length() and expression[i+1]=='1' and expression[i+2]=='0')
                  {
                      lcm=10;
                  }
                     continue;
                  }
                  int an=expression[i+1]-'0';
                  if(i+2 < expression.length() and expression[i+1]=='1' and expression[i+2]=='0')
                  {
                      an=10;
                  }
                  int val = lcm*an/__gcd(lcm,an);
                  lcm=val;
             }
        }
        int ans=0;
        for(int i=0;i<expression.length();i++)
        {
              if(expression[i]=='/')
              {
                   int val=expression[i+1]-'0';
                   if(i+2 < expression.length() and expression[i+1]=='1' and expression[i+2]=='0')
                   {
                       val=10;
                   }
                   int an=lcm/val;

                   int a = expression[i-1]-'0';

                   int b = an*a;
                   if(i-2>=0 and expression[i-2]=='-')
                   {
                      b=-1*b;
                   }
                   if(i-2 >=0 and expression[i-2]=='1' and expression[i-1]=='0')
                   {
                       
                        b=an*10;
                        if(i-3 >=0 and expression[i-3]=='-')
                       {
                          b=-1*b;
                       }
                   }
                   

                   ans+=b;

              }
        }
            cout<<lcm<<" "<<ans<<"\n";
            int num= ans;
            int value = __gcd(num,lcm);
          
            num/=value;
            lcm/=value;
           
            if(lcm < 0 and num> 0)
            {
                 lcm=-1*lcm;
                 num=-1*num;
            }
            return to_string(num)+"/"+to_string(lcm);
       
        return "";
    }
};