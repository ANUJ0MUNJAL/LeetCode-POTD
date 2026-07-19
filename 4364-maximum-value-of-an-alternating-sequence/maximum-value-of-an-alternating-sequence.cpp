class Solution {
public:
    long long maximumValue(int n, int s, int m) {
     
      n--;
      long long ans = s;
      if(n == 0)return s;
      
      if(n & 1)
      {
          ans += (1ll*(n+1)/2)*1ll*m;
          ans -= (n/2);
      }else{
          ans+= 1ll*(n/2)*m;
          ans-=n/2;
          ans++;
      }
      return ans;
    }
};