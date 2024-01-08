int *countBits(int n, int *returnSize)
{
    *returnSize = n + 1;
    int *arr = (int *)malloc((n + 1) * sizeof(int));
    int index = 0, count = 0, ctr = 1;
    arr[index] = 0;
    while (ctr <= n)
    {
        int val = ctr;
        while (val)
        {
            count += val & 1;
            val >>= 1;
        }
        arr[++index] = count;
        count = 0;
        ctr++;
    }
    return arr;
}