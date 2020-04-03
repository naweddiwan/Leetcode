int numSquares(int n)
{
    if (n == 1 || n == 2)
        return n;
    int m = (int)sqrt(n);
    int dp[m + 1][n + 1];

    for (int j = 1; j <= m; j++)
    {
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
                dp[j][i] = 0;
            if (j == 1)
                dp[j][i] = i;

            else if (j * j > i)
            {
                dp[j][i] = dp[j - 1][i];
            }
            else if (j * j <= i)
            {
                dp[j][i] = min(dp[j][i - j * j] + 1, dp[j - 1][i]);
            }
        }
    }
  
    return dp[m][n];
}
