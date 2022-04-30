// In this variant second half of input list is reversed
// to restore defaul list reverse second half again
  ListNode* first_half(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* half = first_half(head);
        ListNode* r_half = reverse(half->next);

        bool res = true;
        while(r_half)
        {
            if (head->val != r_half->val)
                return false;
            
            head = head->next;
            r_half = r_half->next;
        }
        
        return res;
    }
