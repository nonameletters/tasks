class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(size_t i = 0; i < board.size(); i++)
        {
            vector<char> row(10, '.');
            vector<char> col(10, '.');
            
            for(size_t j = 0; j < board.size(); j++)
            {
                if (board[i][j] != '.')
                {
                    size_t v_r = ((int)board[i][j]) - 48;
                    if (row[v_r] == '.')
                    {
                        row[v_r] = board[i][j];
                    }
                    else
                    {
                        return false;
                    }
                }
                
                if (board[j][i] != '.')
                {
                    size_t v_c = ((int)board[j][i]) - 48;
                    if (col[v_c] == '.')
                    {
                        col[v_c] = board[j][i];
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        
        for (size_t k=0; k <= 6; k+=3)
        {
            size_t s = 0 + k;
            size_t e = 2 + k;
            for (size_t z = 0; z <= 6; z+=3)
            {
                vector<char> row(10, '.');
                size_t s_z = 0 + z;
                size_t e_z = 2 + z;
                for(size_t i = s; i <= e; i++)
                {
                    for(size_t j = s_z; j <= e_z; j++)
                    {
                        if (board[i][j] != '.')
                        {
                            size_t v_r = ((int)board[i][j]) - 48;
                            if (row[v_r] == '.')
                            {
                                row[v_r] = board[i][j];
                            }
                            else
                            {
                                return false;
                            }
                        }
                    }
                }
            }

        }
        
        return true;
    }
};
