class Solution {
public:
    int maximumGap(string skill, string station) {
        vector<int> left(skill.length(),0);
        int j = 0;
        for(int i=0;i<station.length();i++)
        {
              if(j < skill.length() and station[i] == skill[j])
              {
                left[j] = i;
                j++;
              }
        }

        vector<int> right(skill.length(),0);

         j = skill.length()-1;
        for(int i=station.length()-1;i>=0;i--)
        {
            if(j >= 0 and station[i] == skill[j])
            {
                right[j] = i;
                j--;
            }
        }
        int ans = 0;
        for(int i=0;i<left.size()-1;i++)
        {
            ans = max(ans,right[i+1] - left[i]);
        }
        return ans;
    }
};