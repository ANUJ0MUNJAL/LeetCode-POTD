class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(st.size() == 0)
        {
            st.insert({start,end});
            return true;
        }
        auto itr = st.lower_bound({start,0});
        if(itr!=st.end() and itr->first <end)return false;
        if(itr == st.begin())
        {
            st.insert({start,end});
            return true;
        }
        itr--;
        if(itr->second > start )
        {
            return false;
        }
        st.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */