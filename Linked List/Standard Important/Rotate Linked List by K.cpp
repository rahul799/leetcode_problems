Rotate Linked List by K
Given a linked list node and a non-negative integer k, rotate the list to the right by k places.

Note: The linked list is guaranteed to have at least one element, and k is guaranteed to be less than or equal to the length of the list.

Constraints

k ≤ n ≤ 100,000 where n is the number of nodes in node
Example 1
Input
Visualize
node =

k = 2
Output
Visualize
3

Example 2
Input
Visualize
node =

k = 4
Output
Visualize


Example 3
Input
Visualize
node =


k = 0
Output
Visualize




Intuition
We can use the 2 pointer approach, to optimize the solution.

Implementation
Take 2 Pointers, I have taken curr & end.
First we move the end pointer k times in the list. Now we run a loop till the end pointer reaches the end of list & simultaneously move the curr pointer as well.
Now, the end pointer points to the last element of the list (when k != size of the list) and to NULL (when k = size of the list). Our curr pointer points to the new tail of the list, i.e. the new last element.
if the end pointer does not point to NULL we connect it to the head of the linked list. Point the node pointer (head) to the next of curr (As that will be the new head) and finally make the next of curr pointer point to NULL.

Example #1
list = 1->2->3->4->5->6, k =2
initially curr = 1, end = 1.

After First while loop: curr = 1(still) & end = 3.


After Second while loop: curr = 4 & end = 6.


Now, we connect 6->1 and our list becomes a circular linked list.

We make the next of Curr pointer, i.e. 5 as the new Head of the list.

And, finally we make the Curr, i.e. 4 as the last element of the list by making the next of it point to NULL.
So, our New List now becomes: 5->6->1->2->3->4

Time Complexity
The time complexity will be \mathcal{O}(n)O(n) as we have traversed the Linked List only once










LLNode* solve(LLNode* node, int k) {
    LLNode *curr = node, *end = node;
    while (k--) {
        end = end->next;
    }
    while (end != NULL and end->next != NULL) {
        curr = curr->next;
        end = end->next;
    }
    if (end != NULL) {
        end->next = node;
        node = curr->next;
        curr->next = NULL;
    }
    return node;
}







