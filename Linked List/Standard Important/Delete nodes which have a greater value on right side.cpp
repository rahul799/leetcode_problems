


Delete nodes which have a greater value on right side


https://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/


Method 2 (Use Reverse) 
Thanks to Paras for providing the below algorithm. 
1. Reverse the list. 
2. Traverse the reversed list. Keep max till now. If next node is less than max, then delete the next node, otherwise max = next node. 
3. Reverse the list again to retain the original order. 
Time Complexity: O(n)







class Solution
{

public:
Node reverse (Node root){
Node prev = NULL; Node* cur = root;
while(cur){
Node* next = cur->next;
cur->next = prev;
prev = cur;
cur = next;
}
return prev;
}
Node compute (Node *head)
 {
// your code goes here
head = reverse(head);

Node cur = head;

int ma = head->data;

Node* prev = head; head head->next;

while(head) { if(head->data>=ma) {

ma = head->data;

prev = head;

head = head->next;

}

else{

prev->next = head->next;

head = prev->next;

reverse(cur);

}

head =

return head
}
