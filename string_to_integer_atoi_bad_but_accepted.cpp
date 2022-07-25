class Solution {
public:
    int myAtoi(string s) {
        size_t i = 0;
        
        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }
        
        if (i >= s.size())
            return 0;
        
        if ((!(s[i] >= '0' && s[i] <= '9')) && (s[i] != '+') && (s[i] != '-'))
            return 0;
        
        int sign = 1;
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }        
        else if (s[i] == '+')
        {
            sign = 1;            
            i++;
        }
        
        if (i >= s.size())
            return 0;
        
        if (!(s[i] >= '0' && s[i] <= '9'))
            return 0;
        
        while (i < s.size() && s[i] == '0')
        {
            i++;
        }
        
        if (i >= s.size())
            return 0;
        
        int res = 0;
        int tst = INT_MAX / 10;
        
        while (i < s.size() && s[i] >= '0' && s[i] <= '9')
        {
            int num = ((size_t) s[i] - 48);
            if (res < tst)
            {
                res = res * 10 + num;
                i++;
                continue;
            }
            
            if ((res == tst) && (num <= 7))
            {
                res = res * 10 + num;
            }            
            else if ((res == tst) && (sign < 0) && (num == 8))
            {
                res = (res * 10 * sign) + (num * sign);
                return res;
            }
            else if ((res >= tst) && (sign < 0))
                return INT_MIN;
            else if ((res >= tst) && (sign > 0))
                return INT_MAX;
            i++;
        }
        
        return res*sign;
        
    }
};
