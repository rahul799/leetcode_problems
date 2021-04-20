


19. Remove Nth Node From End of List
Medium

4974

297

Add to List

Share
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz






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
