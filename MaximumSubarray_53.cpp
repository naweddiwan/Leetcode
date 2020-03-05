    //This is a variation of Kadane's Algorithm that can handle an array even it has all negative elements
    
    int maxSubArray(vector<int>& nums) {
    int max_so_far=0;
        int max_end_here =0;
        int n= nums.size();
        int max1=INT_MIN;
        for(int i=0; i<n; i++)
        {
            max1 =max(max1, nums[i]);
            max_end_here += nums[i];
            if(max_end_here<0)
                max_end_here=0;
            if(max_end_here > max_so_far)
                max_so_far = max_end_here;
        }
        if(max_so_far == 0)
            return max1;
        else
            return max_so_far;
    }
