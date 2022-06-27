class DList
{
    public:
        DList(int key, int value) {this->value = value; this->key = key;};
        int value;
        int key;
 
    public:
        
        DList* next = NULL;
        DList* prev = NULL;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;        
    }
    
    int get(int key) {
        auto it = key_ptr.find(key);
        if (it == key_ptr.end())
        {
            return -1;
        }
        else
        {
            DList* cur = it->second;
    
            update_order(cur);
            
            return tail->value;
        }
        
    }
    
    void put(int key, int value) {
        auto it = key_ptr.find(key);
        if (it != key_ptr.end()) // Key exists
        {
            it->second->value = value;
            // Update order in list;
            update_order(it->second);            
        }
        else // Key NOT exists 
        {
            if ((head == NULL) && (tail == NULL)) // Empty list
            {
                head = new DList(key, value);
                tail = head;
                key_ptr[key] = head;
            }
            else
            {
                if (len < cap)
                {
                    DList* cur = new DList(key, value);
                    key_ptr[key] = cur;
                    update_order(cur);
                    len++;
                }
                else
                {
                    int old_key = head->key;
                    auto it = key_ptr.find(old_key);
                    key_ptr.erase(it);
                    head->value = value;
                    head->key = key;
                    key_ptr[key] = head;
                    update_order(head);
                }
            }
        }
    }
    
    private:
        DList* head = NULL;
        DList* tail = NULL;
        std::unordered_map<int, DList*> key_ptr;
        int cap = 1;
        int len = 1;
    
        void update_order(DList* cur)
        {
            if ((head == tail) && (cur == head))
            {
                return;
            }
            else if (cur == tail)
            {
                return;
            }
            else if(cur == head)
            {
                head = cur->next;
                head->prev = NULL;
            }
            else if ((cur->next != NULL) && (cur->prev != NULL))
            {
                DList* next = cur->next;
                DList* prev = cur->prev;
                
                prev->next = next;
                next->prev = prev;
            }
            tail->next = cur;
            cur->prev = tail;
            cur->next = NULL;
            tail = cur;            
        }
};
