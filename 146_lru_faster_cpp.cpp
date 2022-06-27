typedef list<pair<int,int> > lp;
typedef lp::iterator lp_it;

class LRUCache {
public:
    LRUCache(int capacity) 
    {
        this->cap = capacity;
        
    }
    
    int get(int key) 
    {
        auto res = vals.find(key);
        if (res == end(vals))
        {
            return -1;
        }

        int val = res->second->second;
        cache_order.erase(res->second);
        cache_order.emplace_back(make_pair(key, val));
        vals[key] = --end(cache_order);
        
        return val;   
    }
    
    void put(int key, int value) 
    {
        auto res = vals.find(key);
        if (res == end(vals) && vals.size() < cap)
        {
            cache_order.emplace_back(make_pair(key, value));
            vals.emplace(key, --end(cache_order));
        }
        else if (res == end(vals))
        {
            auto it = begin(cache_order);
            vals.erase(it->first);
            
            cache_order.erase(it);
            cache_order.emplace_back(make_pair(key, value));
            
            vals.emplace(key, --end(cache_order));
        }
        else
        {
            cache_order.erase(res->second);
            cache_order.emplace_back(make_pair(key, value));
            res->second = --end(cache_order);
        }
        
    }
private:
    lp_it cur;
    int cap;
    lp cache_order;
    unordered_map<int, lp_it> vals; 
};
