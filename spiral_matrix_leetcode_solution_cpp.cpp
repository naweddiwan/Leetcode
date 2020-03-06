// 54. Spiral Matrix - LeetCode
//Spiral Order Matrix Traversal 

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<int> res;
    if (n == 0)
        return res;
    int m = matrix[0].size();
    int s_row = 0;
    int e_row = n - 1;
    int e_col = m - 1;
    int s_col = 0;

    while (s_col <= e_col && s_row <= e_row)
    {
        for (int i = s_col; i <= e_col; i++)
            res.push_back(matrix[s_row][i]);
        s_row++;

        for (int i = s_row; i <= e_row; i++)
            res.push_back(matrix[i][e_col]);
        e_col--;

        if (s_row <= e_row)
        {
            for (int i = e_col; i >= s_col; i--)
                res.push_back(matrix[e_row][i]);
            e_row--;
        }

        if (s_col <= e_col)
        {
            for (int i = e_row; i >= s_row; i--)
                res.push_back(matrix[i][s_col]);
            s_col++;
        }
    }
    return res;
}
