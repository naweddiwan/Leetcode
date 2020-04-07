 // find first where nums[i] > nums[i-1]
    // then from i+1 to n find if there is a number greater than nums[i], if yes then replace
    // finally sort the array from i to n;
    // if the array is decreasing order sort from 0 to n;
    
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int flag =0;
        for(int i =n-1; i>=1;i--)
        {
            if(nums[i] > nums[i-1])
            {
                swap(nums[i], nums[i-1]); // swap for the first time
                int temp =nums[i-1];
                int MIN =INT_MAX;
                int ind = i-1;
             
                for(int j=i+1; j<n; j++)
                {
                   
                   if(MIN > nums[j] && nums[j] > nums[i])
                   {
               
                       ind = j;
                       MIN = nums[j];
                   }
                }
               
                swap(nums[i-1], nums[ind]);
                sort(nums.begin()+i, nums.end());
                flag=1;
                break;
                
            }
            
        }
        if(flag!=1)
        sort(nums.begin(), nums.end());
        
    }
