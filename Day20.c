/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array.
 For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero:
  [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3].
Since there are 6 such subarrays, the output is 6.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int hash(int x)
{
    return (x % MAX + MAX) % MAX;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int *freq = (int *)calloc(MAX, sizeof(int));

    int prefixSum = 0;
    long long count = 0;

    freq[hash(0)] = 1;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        int h = hash(prefixSum);
        count += freq[h];
        freq[h]++;
    }

    printf("%lld\n", count);

    free(arr);
    free(freq);
    return 0;
}