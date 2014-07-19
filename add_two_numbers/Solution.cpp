/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int c = 0;
        ListNode *head = NULL;
        ListNode *prevNode = NULL;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int ret = val1 + val2 + c;
            c = ret / 10;
            ListNode *newNode = new ListNode(ret % 10);
            if (!head) {
                head = newNode;
            } else {
                prevNode->next = newNode;
            }
            
            prevNode = newNode;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        
        if (c != 0) prevNode->next = new ListNode(c);
        return head;
    }
};