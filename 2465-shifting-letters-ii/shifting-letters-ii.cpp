class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> arr(s.length()+1,0);

        for(int i=0;i<shifts.size();i++)
        {
            if(shifts[i][2]){
              arr[shifts[i][0]]+=1;
              arr[shifts[i][1]+1]-=1;
            }else{
                arr[shifts[i][0]]-=1;
                arr[shifts[i][1]+1]+=1;
            }
        }
        int sum = 0;
        for(int i=0;i<arr.size()-1;i++)
        {
                sum+=arr[i];

                if(sum < 0)
                {
                    int val = abs(sum);
                    val %= 26;
                    
                    while(val)
                    {
                        if(s[i]=='a')
                        {
                            s[i]='z';
                        }else{
                            int b = s[i] - 'a';
                            s[i]='a'+b-1;
                        }
                        val--;
                    }

                }else if(sum > 0)
                {
                       int val = sum;
                       val %= 26;

                       while(val)
                       {
                          if(s[i]=='z')
                          {
                            s[i]='a';
                          }else{
                            int b = s[i]-'a';
                            s[i]='a'+b+1;
                          }
                          val--;
                       }
                }
        }
        return s;
    }
};