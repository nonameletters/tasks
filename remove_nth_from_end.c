    // This is recursion approach
    // It is also possible use approach with pointers
    // Maintain two pointers and update one with a delay of n steps.
    void removeN(ListNode** node, int& fl, int n)
    {
        if ((*node) != NULL)
        {
            removeN(&((*node)->next), fl, n);
        }
        fl++;
        
        if (fl != n)
            return;
        
        if ((*node)->next == NULL)
        {
            delete (*node);
            (*node) = NULL;
            return;
        }
        
        ListNode* nxt = (*node)->next;
        (*node)->val = (*node)->next->val;
        (*node)->next = (*node)->next->next;
        delete nxt;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int fl = -1;
        removeN(&head, fl, n);
        return head;
    }
