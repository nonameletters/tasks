class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        
        for(size_t i = 0;;i++)
        {
            for(size_t j = 0; j < strs.size(); j++)
            {
                if (i >= strs[j].size())
                {
                    return res;
                }
                else if (strs[0][i] != strs[j][i])
                {
                    return res;
                }
            }
            
            res += strs[0][i];
        }
        return res;
    }
};
