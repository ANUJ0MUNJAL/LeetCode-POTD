class FindSumPairs {
public:
    map<int,int> mp;
    multiset<int> st;
    map<int,int> count1;
    vector<int> nums;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        nums = nums1;
        for(int i=0;i<nums2.size();i++)
        {
            mp[i] = nums2[i];
            count1[nums2[i]]++;
            st.insert(nums2[i]);
        }
    }
    
    void add(int index, int val) {
        int value = mp[index];
        st.erase(st.find(value));
        st.insert(value + val);
        mp[index]=value+val;
        count1[value+val]++;
        count1[value]--;

    }
    
    int count(int tot) {
        int ans = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            int value = tot - nums[i];
            if(st.find(value) != st.end())
            {
                ans += count1[value];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */