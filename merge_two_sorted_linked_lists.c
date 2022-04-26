  // We link two lists in one. List1 and list2 are modified
  // The main idea use pointer to previos compared element
  // we don't use auxiliary memory
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* hl1 = list1;
        ListNode* hl2 = list2;
        ListNode* prev = NULL;
        
        while(list1 && list2)
        {
            
            if(list1->val <= list2->val)
            {
                if (!prev)
                {
                    prev = list1;                    
                    list1 = list1->next;
                }
                else
                {
                    prev->next = list1;
                    prev = list1;
                    list1 = list1->next;
                }
            }
            else
            {
                if (!prev)
                {
                    prev = list2;                    
                    list2 = list2->next;
                }
                else
                {
                    prev->next = list2;
                    prev = list2;
                    list2 = list2->next;
                }
            }
        }
        
        
        if(!hl1)
        {
            return hl2;
        }
        else if (!hl2)
        {
            return hl1;
        }
        else if (hl1->val <= hl2->val)
        {
            if (!list1)
                prev->next = list2;
            if (!list2)
                prev->next = list1;
            return hl1;
        }
        else
        {
            if (!list1)
                prev->next = list2;
            if (!list2)
                prev->next = list1;
            return hl2;
        }
        
    }
