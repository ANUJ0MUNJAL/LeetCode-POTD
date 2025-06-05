class Solution {
public:
    void dfs(char node, set<char>& component, unordered_map<char, set<char>>& graph, unordered_set<char>& visited) {
        visited.insert(node);
        component.insert(node);
        for (char neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                dfs(neighbor, component, graph, visited);
            }
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, set<char>> graph;

        for (int i = 0; i < s1.size(); i++) {
            char a = s1[i], b = s2[i];
            graph[a].insert(b);
            graph[b].insert(a);
        }

        unordered_map<char, char> smallestRep; 
        unordered_set<char> visited;

        for (char c = 'a'; c <= 'z'; c++) {
            if (!visited.count(c) && graph.count(c)) {
                set<char> component;
                dfs(c, component, graph, visited);
                char minChar = *component.begin(); 
                for (char ch : component) {
                    smallestRep[ch] = minChar;
                }
            } else if (!visited.count(c)) {
                
                smallestRep[c] = c;
            }
        }
        string result = "";
        for (char ch : baseStr) {
            result += smallestRep[ch];
        }

        return result;
    }
};
