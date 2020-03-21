vector<int> getRow(int rowIndex)
{
    int **arr = new int *[rowIndex + 1];
    for (int i = 0; i <= rowIndex; i++)
        arr[i] = new int[i + 1];
    
    vector<int> res;
    for (int i = 0; i <= rowIndex; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];

            if (i == rowIndex)   
                res.push_back(arr[i][j]); // Storing the final answer in the res array;
        
        }
    }
    for (int i = 0; i <= rowIndex; i++)
        delete[] arr[i];

    delete[] arr;
    return res;
}
