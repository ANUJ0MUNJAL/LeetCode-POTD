class Solution {
public:
    long long solve(long long left,bool iseven)
    {
        long long val= left;
        if(!iseven)left/=10;
        while(left > 0)
        {
            val=val*10 + left % 10;
            left/=10;
        }
        return val;
    }
    string nearestPalindromic(string n) {
            long long num = stoll(n);

            if(num <= 10)return to_string(num-1);
            if(num == 11)return "9";
            if(n =="999999999999999999")return "1000000000000000001";

            int len=n.length();
            long long left=stoll(n.substr(0,(len+1)/2));

            vector<long long> ans;

            ans.push_back(solve(left-1,len % 2 == 0));
            ans.push_back(solve(left,len % 2 == 0));
            if(left < 999999999)
            {
                ans.push_back(solve(left+1,len % 2 == 0));
            }else{
                ans.push_back(stoll("1"+string(len-1,'0')+"1"));
            }

            ans.push_back(pow(10,len-1)-1);
            ans.push_back(pow(10,len)+1);
            long long near=0,mini=LLONG_MAX;
            for(auto j: ans)
            {
                   if(j == num)continue;
                   long long diff= abs(j-num);
                   if(diff < mini || (diff == mini and j < near))
                   {
                    mini=diff;
                    near=j;
                   }
            }
            return to_string(near);


    }
};