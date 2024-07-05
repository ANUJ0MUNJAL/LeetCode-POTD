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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> temp1;
        ListNode* temp=head->next;
        if(temp == NULL){
             return {-1,-1};
        }
    
        if(temp -> next == NULL)return {-1,-1};
        ListNode* prev=head;
        int pos=2;
        int mini=INT_MAX;
        while(temp->next != NULL){
              ListNode * curr=temp->next;
          
              if(temp->val > curr->val and temp->val > prev->val){
                if(temp1.size())
                  mini=min(mini,pos - temp1.back());
                  temp1.push_back(pos);
              }
              if(temp->val < prev->val and temp->val < curr->val){
                if(temp1.size())
                   mini=min(mini,pos - temp1.back());
                 temp1.push_back(pos);
              }
              pos++;
              prev=temp;
              temp=curr;
        }
     if(temp1.size() == 0 || mini==INT_MAX){
        return {-1,-1};
     }
        return {mini,temp1[temp1.size()-1]-temp1[0]};

        

    }
};