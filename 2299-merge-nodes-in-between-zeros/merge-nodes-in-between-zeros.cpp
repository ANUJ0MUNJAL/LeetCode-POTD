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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * dummy = new ListNode(-1);
        ListNode* curr=dummy;
        ListNode* temp=head;
        while(temp != NULL){
              int val=0;
              temp=temp->next;
              while(temp!=NULL and temp->val != 0){
                 val+=temp->val;
                 temp=temp->next;
              }
              if(val == 0){
                break;
              }
              ListNode* newnode = new ListNode(val);
              curr->next=newnode;
              curr=newnode;
        }
        return dummy->next;
    }
};