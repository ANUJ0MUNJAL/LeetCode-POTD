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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for(auto &j: nums){
            st.insert(j);
        }
        vector<int> ans;
        ListNode* temp=head;
        while(temp!=NULL){
        if(st.find(temp->val)==st.end())
            ans.push_back(temp->val);
            temp=temp->next;
        }

        ListNode* dummy=new ListNode(-1);
        ListNode* prev=dummy;
        for(int i=0;i<ans.size();i++){
            ListNode* temp=new ListNode(ans[i]);
            prev->next=temp;
            prev=temp;
        }
        return dummy->next;

    }
};