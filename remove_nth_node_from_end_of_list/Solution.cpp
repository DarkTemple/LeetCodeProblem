class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int size = 0;
        ListNode *curNode = head;
        ListNode *prevNode = NULL;
        while (curNode) {
            size++;
            curNode = curNode->next;
        }
        
        curNode = head;
        int step = size - n;
        while (step--) {
            prevNode = curNode;
            curNode = curNode->next;
        }
        
        if (prevNode) {
            prevNode->next = curNode->next;
        } else {
            head = curNode->next;
        }
        
        delete curNode;
        return head;
    }
};