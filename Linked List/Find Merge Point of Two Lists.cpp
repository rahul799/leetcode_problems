To calculate the merge point, first calculate the difference in the sizes of the linked lists. Move the pointer of the smaller linked list by this difference.
Increment both pointers  till you reach the merge point.


https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

Get count of the nodes in the first list, let count be c1.
Get count of the nodes in the second list, let count be c2.
Get the difference of counts d = abs(c1 – c2)
Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes.
Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)
int getCount(Node* head)
{
  Node* current = head;
  int count = 0;

  while (current != NULL)
  {
    count++;
    current = current->next;
  }

  return count;
}

int getNode(int d, Node* head1, Node* head2)
{
  int i;
  Node* current1 = head1;
  Node* current2 = head2;

  for(i = 0; i < d; i++)
  {
    if(current1 == NULL)
    {  return -1; }
    current1 = current1->next;
  }

  while(current1 !=  NULL && current2 != NULL)
  {
    if(current1 == current2)
      return current1->data;
    current1= current1->next;
    current2= current2->next;
  }

  return -1;
}

int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    int c1 = getCount(headA);
  int c2 = getCount(headB);
  int d;

  if(c1 > c2)
  {
    d = c1 - c2;
    return getNode(d, headA, headB);
  }
  else
  {
    d = c2 - c1;
    return getNode(d, headB, headA);
  }
}
