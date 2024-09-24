class Tree {
    private:
        struct TreeNode {
            TreeNode* children[10];
            bool isEnd;

            TreeNode() {
                for (int i = 0; i < 10; i++) {
                    children[i] = nullptr;
                }
                isEnd = false;
            }
        };

        TreeNode* root;

    public:
        Tree() {
            root = new TreeNode();
        }

        void insert(int num) {
            TreeNode* node = root;
            std::string str = std::to_string(num);

            for (int i = 0; i < str.length(); i++) {
                int digit = str[i] - '0';
                if (node->children[digit] == nullptr) {
                    node->children[digit] = new TreeNode();
                }
                node = node->children[digit];
            }
            node->isEnd = true;
        }

        int longestCommonPrefixLength(int num) {
            TreeNode* node = root;
            std::string str = std::to_string(num);
            int len = 0;

            for (int i = 0; i < str.length(); i++) {
                int digit = str[i] - '0';
                if (node->children[digit] == nullptr) {
                    return len;
                }
                node = node->children[digit];
                len++;
            }

            return len;
        }
    };


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
      Tree tree;
        int maxi = 0;

        for (int num : arr1) {
            tree.insert(num);
        }

        for (int num : arr2) {
            maxi = max(maxi, tree.longestCommonPrefixLength(num));
        }

        return maxi;
    }
};