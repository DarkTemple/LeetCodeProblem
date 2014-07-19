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
    ListNode *insertionSortList(ListNode *head) {
        if (!head) return NULL;
        ListNode *assistNode = new ListNode(0);
        assistNode->next = head;
        ListNode *cur = head;
        ListNode *prev = assistNode;
        while (cur && cur->next) {
            while (cur != prev) {
                if (cur->next->val <= prev->next->val) {
                    ListNode *moveNode = cur->next;
                    cur->next = moveNode->next;
                    moveNode->next = prev->next;
                    prev->next = moveNode;
                    break;
                } else {
                    prev = prev->next;
                }
            }
            
            if (cur == prev) cur = cur->next;
            prev = assistNode;
        }
        
        head = assistNode->next;
        delete assistNode;
        return head;
    }
};