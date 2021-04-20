
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.



class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if( k == 1 || head == nullptr || getCount(head) < k )
            return head;  
        
        ListNode* curr = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        int count = 0;         
        while(curr != NULL && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++count;
        }
  
        head->next = reverseKGroup(next, k);
        return prev;
    }
private:
    int getCount(ListNode* node){
        int count = 0;
        while(node != nullptr){
            node = node->next;
            ++count;
        }
        return count;
    }
};




