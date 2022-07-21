class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = i; j < matrix.size(); j++)
            {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix.size() / 2; j++)
            {
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][(matrix.size() - 1) - j];
                matrix[i][(matrix.size() - 1) - j] = t;
            }
        }
        
    }
};
