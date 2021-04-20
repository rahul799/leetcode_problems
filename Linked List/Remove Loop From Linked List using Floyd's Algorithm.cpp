https://neuralnetworksai.blogspot.com/2019/04/remove-loop-from-linked-list-using.html



Remove Loop From Linked List using Floyd's Algorithm



void remove_loop(Node *head){
    Node *slow = head;
    Node *fast = head;
    if (!head || !(head->next))
        return;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    
    // No Loop exixts
    if (slow != fast){
        std::cout << "No Loop" << std::endl;
        return;
    }
    
    // When Loop exists
    slow = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = nullptr;
}



