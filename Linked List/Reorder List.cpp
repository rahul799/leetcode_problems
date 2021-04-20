143. Reorder List

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.






class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = nullptr, *curr = slow, *tmp;
        while(curr){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        ListNode *n1 = head, *n2 = prev;
        while(n2->next){
            // I don't want to loost n1->next
            tmp = n1->next;
            n1->next = n2;
            n1 = tmp;
          // I don't want to loose n2->next  
            tmp = n2->next;
            n2->next = n1;
            // moving n2 one step forward
            n2 = tmp;
        }
    }
};
