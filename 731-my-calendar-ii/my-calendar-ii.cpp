class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    map<int,int> mp;
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int book=0;
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            book+=it->second;
            if(book == 3)
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */