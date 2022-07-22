class Solution {
public:
    typedef struct _ic
    {
        size_t ind = 0;
        size_t count = 0;
    } ic;
    
    int firstUniqChar(string s) {
        ic arr[26];
        for (size_t i = 0; i < s.size(); i++)
        {
            size_t ind = ((size_t) s[i]) - 97;
            arr[ind].ind = i;
            arr[ind].count += 1;
        }
        
        int res = INT_MAX;
        for (size_t i = 0; i < sizeof(arr)/sizeof(ic); i++)
        {
            if ((arr[i].count == 1) && (arr[i].ind < res))
            {
                res = arr[i].ind;
            }
        }
        
        if (res == INT_MAX)
        {
            res = -1;
        }
        
        return res;
    }
};
