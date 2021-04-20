
445. Add Two Numbers II
Medium

2005

188

Add to List

Share
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7









class Solution {
    
    // reverse the link list 
    
     ListNode* Reverse( ListNode* head){
          ListNode* curr = head;
         ListNode* prev = NULL;
         ListNode* next = NULL;
         
         while(curr != NULL){
             next = curr->next;
             curr->next = prev;
             prev  = curr;
             curr = next;
         }
         return prev;
     }
    
      ListNode* AddNumber(ListNode* l1, ListNode* l2) {
        int carry =0;
        ListNode* l= new ListNode(0);
        ListNode* ans = l;
        while(l1 || l2 || carry){
            int v1 =0,v2=0;
            if(l1){
                v1= l1->val;
                l1= l1->next; 
            }
            if(l2){
                v2 = l2->val;
                l2=l2->next;
            }
           int sum = v1+v2+carry;
            carry = sum/10;
            l->next = new ListNode(sum%10);
            l = l->next;
        }
        return ans->next ;
        
        
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* nl1 = Reverse(l1);
         ListNode* nl2 =  Reverse(l2);
        ListNode* ans = AddNumber(nl1,nl2);
        return Reverse(ans);
    }
};
