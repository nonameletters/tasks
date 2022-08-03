class Solution {
public:
    int romanToInt(string s) {
        
        map<char, int> digits {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            res += digits[s[i]];
            if ((i > 0) && (s[i] == 'V' || s[i] == 'X') && (s[i-1] == 'I'))
            {
                res -= 2;
            }
            else if ((i > 0) && (s[i] == 'L' || s[i] == 'C') && (s[i - 1] == 'X'))
            {
                res -= 20;
            }
            else if ((i > 0) && (s[i] == 'D' || s[i] == 'M') && (s[i - 1] == 'C'))
            {
                res -= 200;
            }
                                
        }
        
        return res;
    }
};
