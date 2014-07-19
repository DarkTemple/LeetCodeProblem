/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *nextNode = NULL;
        RandomListNode *newNode = NULL;
        RandomListNode *origHead = head;
        while (head) {
            newNode = new RandomListNode(head->label);
            nextNode = head->next;
            head->next = newNode;
            newNode->next = nextNode;
            head = nextNode;
        }
        
        head = origHead;
        while (head) {
            head->next->random = head->random ? head->random->next : NULL;
            head = head->next->next;
        }
        
        head = origHead;
        newNode = head ? head->next : NULL;
        RandomListNode *newHead = newNode;
        while (head) {
            head->next = head->next->next;
            head = head->next;
            newNode->next = head ? head->next : NULL;
            newNode = head ? head->next : NULL;
        }
        
        return newHead;
    }
};