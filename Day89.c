/*Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible). */
#include <stdio.h>

int canAllocate(int pages[], int n, int m, int limit)
{
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pages[i] > limit)
            return 0;

        if (sum + pages[i] > limit)
        {
            students++;
            sum = pages[i];
        }
        else
        {
            sum += pages[i];
        }
    }

    return students <= m;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int pages[1000];
    int maxPage = 0, total = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
        if (pages[i] > maxPage)
            maxPage = pages[i];
        total += pages[i];
    }

    if (m > n)
    {
        printf("-1");
        return 0;
    }

    int left = maxPage;
    int right = total;
    int ans = total;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (canAllocate(pages, n, m, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}