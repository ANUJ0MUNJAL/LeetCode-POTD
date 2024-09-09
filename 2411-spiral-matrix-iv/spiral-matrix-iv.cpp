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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> arr(m,vector<int>(n,-1));
        int startingrow=0,startingcol=0,endingrow=m-1,endingcol=n-1;
        ListNode* temp=head;
        while(temp != NULL)
        {
            for(int i=startingcol;i<=endingcol;i++)
            {
                  arr[startingrow][i]=temp->val;
                  temp=temp->next;
                  if(temp == NULL)break;
            }
            if(temp == NULL)break;
            startingrow++;
            for(int i=startingrow;i<=endingrow;i++)
            {
                  arr[i][endingcol]=temp->val;
                  temp=temp->next;
                  if(temp == NULL)break;
            }
            if(temp == NULL)break;
            endingcol--;
            for(int i=endingcol;i>=startingcol;i--)
            {
                  arr[endingrow][i]=temp->val;
                  temp=temp->next;
                  if(temp == NULL)break;
            }
            if(temp == NULL)break;
            endingrow--;
            for(int i=endingrow;i>=startingrow;i--)
            {
                 arr[i][startingcol]=temp->val;
                  temp=temp->next;
                  if(temp == NULL)break;
            }
            if(temp == NULL)break;
            startingcol++;
        }
        return arr;
    }
};