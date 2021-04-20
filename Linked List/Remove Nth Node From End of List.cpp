

19. Remove Nth Node From End of List
Medium

3630

239

Add to List

Share
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.






// I will make the diff between fast and slow pointer of n and move both of them
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        
		// move fast pointer to the n + 1 element
        while (n--) { fast = fast->next; }
        
        // handle edge case: given n is always valid, 
        // if fast reached the end, we need to remove the first element
        if (fast == nullptr) return head->next;

        // move both pointers at the same time maintaing the difference
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // slow will be pointing to the element before the one we want to remove
        slow->next = slow->next->next;
        
        return head;
    }
};
