class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        
        if (haystack.size() < needle.size())
            return -1;
        
        for (size_t i = 0; i < haystack.size(); i++)
        {
            size_t j = 0;
            size_t k = i;
            while(haystack[k] == needle[j] && j < needle.size() && k < haystack.size())
            {
                k++;
                j++;
            }
            
            if (j == needle.size())
                return i;
        }
        
        return -1;
    }
};
