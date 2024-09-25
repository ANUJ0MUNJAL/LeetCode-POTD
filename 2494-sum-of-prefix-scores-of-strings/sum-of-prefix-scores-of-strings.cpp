
struct Node {
    Node *links[26];
    bool flag = false;
    int count=0;
  
    bool containKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node,int i) {
        links[ch - 'a'] = node;
        
    }

    Node *get(char ch) {
        return links[ch - 'a'];
    }
   
    void setEnd(int i) {
      
        flag = true;
    }
  
    bool isEnd() {
        return flag;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
      
        root = new Node();
    }

    void insert(string word,int index) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                node->put(word[i], new Node(),index);
            }
            
            node = node->get(word[i]);
            node->count++;
            
        }
        node->setEnd(index);
    }
    int count(string word)
    {
       Node* node= root;
       int ans=0;
       for(int i=0;i<word.size();i++)
       {
           node=node->get(word[i]);
           ans+=node->count;
          
       }
       return ans;
    }
    bool search(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
class Solution {
public:
   vector<int> ans;
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *root = new Trie();
        ans.resize(words.size(),0);
        for(int i=0;i<words.size();i++)
        {
            root->insert(words[i],i);
        }
         for(int i=0;i<words.size();i++)
        {
            ans[i]=root->count(words[i]);
            // for(auto j: ans)cout<<j<<" ";
            // cout<<"\n";
        }
        return ans;
    }
};