https://leetcode.com/problems/reverse-nodes-in-k-group/


Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5






ptr = current, pptr = previous, nptr = next, 

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* ptr = head, *nptr = NULL, *pptr = NULL;
        int count = 0;
        int size = 0;
        while(ptr){
            ptr = ptr->next;
            size++;
        }
        if(size < k){
            return head;
        }
        ptr = head;
        while(ptr && count < k){
            nptr = ptr->next;
            ptr->next = pptr;
            pptr = ptr;
            ptr = nptr;
            count++;
        }
        if(nptr != NULL)
            head->next = reverseKGroup(nptr, k);
        return pptr;
    }
};
