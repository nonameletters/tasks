class Solution {
public:
    
    void generate(int open, int closed, int n, vector<string>& res, string str)
    {
        if (open == n && closed == n)
        {
            res.push_back(str);
            return;
        }
        
        if (open < n)
        {
            generate(open + 1, closed, n, res, str + "(");
        }
        
        if (closed < open)        
        {
            generate(open, closed+1, n, res, str + ")");
        }
            
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        generate(0, 0, n, res, str);
        return res;
    }
};
