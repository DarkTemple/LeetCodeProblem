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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *post = swapPairs(head->next->next);
        ListNode *newHead = head->next;
        newHead->next = head;
        head->next = post;
        return newHead;
    }
};