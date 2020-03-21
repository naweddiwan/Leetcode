int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
        
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int max1 = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
            if (dp[i] > max1)
                max1 = dp[i];
        }
    }
    return max1;
}
