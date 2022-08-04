class Solution {
public:
    bool isValid(string s) {
        map<char, int> brc {{'(', 1}, {')', -1}, {'{', 2}, {'}', -2}, {'[', 3}, {']', -3}};
        vector<int> stk;
        
        int dg = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            dg = brc[s[i]];
            if (dg > 0)
            {
                stk.push_back(dg);
                continue;
            }
            
            if ((stk.size() > 0) && (stk.back() == (dg*(-1))))
            {
                stk.pop_back();
            }
            else
            {
                return false;
            }
        }
        
        if (stk.size() != 0)
        {
            return false;
        }
        
        return true;
    }
};
