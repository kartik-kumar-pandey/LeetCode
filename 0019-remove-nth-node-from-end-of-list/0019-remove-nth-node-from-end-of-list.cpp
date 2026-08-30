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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int i=0;
        while(i<n){
            
            i++;
            temp=temp->next;
        }
        if (temp == nullptr) {
            return head->next;
        }

        ListNode* temp2=head;
        ListNode* prev=temp2;
        while(temp!=nullptr){
            temp=temp->next;
            prev=temp2;
            temp2=temp2->next;
        }
        prev->next=temp2->next;

return head;

    }
};