class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode *final, *temp1 = list1, *temp2 = list2;

        if (list1->val < list2->val) {
            final = temp1;
            temp1 = temp1->next;
        } else {
            final = temp2;
            temp2 = temp2->next;
        }

        ListNode *head = final;   // store head

        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val < temp2->val) {
                final->next = temp1;
                temp1 = temp1->next;
            } else {
                final->next = temp2;
                temp2 = temp2->next;
            }
            final = final->next;
        }

        while (temp1) {
            final->next = temp1;
            temp1 = temp1->next;
            final = final->next;
        }

        while (temp2) {
            final->next = temp2;
            temp2 = temp2->next;
            final = final->next;
        }

        return head;
    }
};