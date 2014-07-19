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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *assistNode = new ListNode(0);
        assistNode->next = head;
        ListNode *prevNode = assistNode, *curNode = head;
        while (curNode && curNode->next) {
            if (curNode->val != curNode->next->val) {
                prevNode = curNode;
                curNode = curNode->next;
            } else {
                int val = curNode->val;
                while (curNode && curNode->val == val) {
                    ListNode *post = curNode->next;
                    delete curNode;
                    curNode = post;
                }
                
                prevNode->next = curNode;
            }
        }
        
        head = assistNode->next;
        delete assistNode;
        return head;
    }
};