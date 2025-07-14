/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string temp = "";
        while(head != NULL)
        {
            temp+=to_string(head->val);
            head=head->next;
        }
        reverse(temp.begin(),temp.end());
        int ans = 0;
        for(int i=0;i<temp.length();i++)
        {
            if(temp[i] == '1')
            {
                int mask = 1 << i;
                ans |= mask;
            }
        }
        return ans;
    }
};