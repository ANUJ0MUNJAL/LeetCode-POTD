class CustomStack {
public:
    deque<int> dq;
    int size;
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        if(dq.size() == size)return;
        dq.push_front(x);
    }
    
    int pop() {
        if(dq.size()==0)return -1;
        int val =dq.front();
        dq.pop_front();
        return val;
    }
    
    void increment(int k, int val) {
        stack<int> st;
        while(!dq.empty() and k--)
        {
             st.push(dq.back()+val);
             dq.pop_back();
        }
        while(!st.empty())
        {
            dq.push_back(st.top());
            st.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */