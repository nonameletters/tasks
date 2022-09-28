class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> order;
        
        size_t result = 0;
        size_t l = 0, r = 0;
        
        
        order[s[r]] = order[s[r]] + 1;
        int max_order = 1;
        while ((l <= r) && (l < s.size()))
        {   
            if ((r - l + 1) - max_order <= k)
            {
                if (r < s.size())
                {
                    result = max(result, (r - l + 1));
                    r++;
                    order[s[r]] = order[s[r]] + 1;
                    if (max_order < order[s[r]])
                        max_order = order[s[r]];
                }
                else
                {
                    order[s[l]] = order[s[l]] - 1;
                    l++;                    
                }
            }
            else
            {
                order[s[l]] = order[s[l]] - 1;
                l++;
            }
        }
        
        return result;
    }
};
