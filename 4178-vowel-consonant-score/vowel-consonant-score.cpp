class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowel = 0;
        int digit = 0,space = 0;
        for(auto j: s)
        {
            if(j == 'a' or j =='e' or j == 'i' or j =='o' or j=='u')vowel++;
            if(j >='0' and j <='9')digit++;
            if(j == ' ')space++;
        }

        int cons = s.length()-vowel-space-digit;

        if(cons > 0)
        {
             return vowel/cons;
        }
        return 0;
    }
};