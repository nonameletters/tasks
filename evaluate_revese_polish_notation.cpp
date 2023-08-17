class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> res;
        int val1 = 0;
        int val2 = 0;
        for (auto it = begin(tokens); it != end(tokens); it++)
        {
            if (*it == "+")
            {
                val1 = res.back();
                res.pop_back();
                val2 = res.back();
                res.pop_back();
                res.push_back(val2 + val1);
            }
            else if (*it == "-")
            {
                val1 = res.back();
                res.pop_back();
                val2 = res.back();
                res.pop_back();
                res.push_back(val2 - val1);
            }
            else if (*it == "*")
            {
                val1 = res.back();
                res.pop_back();
                val2 = res.back();
                res.pop_back();
                res.push_back(val2 * val1);
            }
            else if (*it == "/")
            {
                val1 = res.back();
                res.pop_back();
                val2 = res.back();
                res.pop_back();
                res.push_back(val2 / val1);
            }
            else
            {
                res.push_back(stoi(*it));
            }
        }
        return res.back();
    }
};
