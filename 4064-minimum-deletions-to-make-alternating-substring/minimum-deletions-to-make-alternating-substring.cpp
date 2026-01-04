class Solution {
public:
    int n;
    static const int N = 200000;

    struct Node{
        char first, last;
        int mindel;
        Node(char a=' ', char b=' ', int d=0){
            first = a;
            last = b;
            mindel = d;
        }
    };
   
    Node t[4*N + 10];

    Node merge(const Node &L, const Node &R){
        if(L.first == ' ') return R;
        if(R.first == ' ') return L;

        int extra = (L.last == R.first) ? 1 : 0;
        return Node(L.first, R.last, L.mindel + R.mindel + extra);
    }
    
    void build(int id, int l, int r, const string &s){
        if(l == r){
            t[id] = Node(s[l], s[l], 0);
            return;
        }
        int mid = (l+r)/2;
        build(id*2, l, mid, s);
        build(id*2+1, mid+1, r, s);
        t[id] = merge(t[id*2], t[id*2+1]);
    }

    void update(int id, int l, int r, int pos, char val){
        if(l==r){
            t[id] = Node(val, val, 0);
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid){
            update(id*2, l, mid, pos, val);
        }
        else{
            update(id*2+1, mid+1, r, pos, val);
        }
        t[id] = merge(t[id*2], t[id*2+1]);
    }

    Node query(int id, int l, int r, int ql, int qr){
        if(qr<l || r<ql) return Node();
        if(ql<=l && r<=qr) return t[id];
        int mid = (l+r)/2;
        return merge(query(id*2,l,mid,ql,qr), query(id*2+1,mid+1,r,ql,qr));
    }
    
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        n = s.size();
        build(1,0,n-1,s);
        vector<int> ans;
        for(auto q: queries){
            if(q[0] == 1){
                int j = q[1];
                s[j] = (s[j] == 'A') ? 'B' : 'A';
                update(1,0,n-1,j,s[j]);
            }
            else{
                int l = q[1], r = q[2];
                if(l == r){
                    ans.push_back(0);
                    continue;
                }
                Node res = query(1,0,n-1,l,r);
                ans.push_back(res.mindel);
            }
        }
        return ans;
    }
};
