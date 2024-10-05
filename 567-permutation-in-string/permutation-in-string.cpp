class Solution {
    private:
       bool checkequal(int count1[],int count2[])
       {
           for(int i=0;i<26;i++)
           {
               if(count1[i]!=count2[i])
               {
                   return 0;
               }
           }
           return 1;
       }
public:
    bool checkInclusion(string s1, string s2) {
        int count[26]={0};
        for(int i=0;i<s1.length();i++)
        {
            int index=s1[i]-'a';
            count[index]++;
        }
        int i=0;
        int count1[26]={0};
        int dibba=s1.length();
        while(i<dibba&&i<s2.length())
        {
            int index=s2[i]-'a';
            count1[index]++;
            i++;
        }
        if(checkequal(count,count1))
        {
            return 1;
        }
        while(i<s2.length())
        {
            char newchar=s2[i];
            int index=newchar-'a';
            count1[index]++;
            char oldchar=s2[i-dibba];
            index=oldchar-'a';
            count1[index]--;
            i++;
            if(checkequal(count,count1))
            {
                return 1;
            }
        }
        return 0;
    }
};