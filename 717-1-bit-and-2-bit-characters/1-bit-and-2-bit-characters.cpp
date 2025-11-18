class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(int i=0;i<bits.size();i++)
        {
            if(i == bits.size()-1 and bits[i]==0)return true;
            if(bits[i] == 0)continue;
            else{
                i++;
            }
        }
        return false;
    }
};