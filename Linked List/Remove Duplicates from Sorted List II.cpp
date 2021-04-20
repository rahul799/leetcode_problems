82. Remove Duplicates from Sorted List II


Share
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3






class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        //ListNode* cur = dummy;
        head = dummy;
        while(head->next && head->next->next) {
        	if(head->next->val == head->next->next->val) {
        		int value = head->next->val;
        		while(head->next && head->next->val == value) {
        			head->next = head->next->next;
        		}
        	} else {
        		head = head->next;
        	}
        }
        return dummy->next;
    }
};
