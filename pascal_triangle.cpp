class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res {{1}};
        
        for(size_t i = 1; i < numRows; i++)
        {
            res.push_back({});
            size_t pi = res.size() - 1;
            res[pi].push_back(res[pi - 1][0]);
            for(size_t j = 0; j + 1 < res[pi - 1].size(); j++)
            {
                res[pi].push_back(res[pi-1][j] + res[pi-1][j + 1]);
            }
            res[pi].push_back(res[pi - 1][res[pi - 1].size() - 1]);
        }
        return res;
    }
};
