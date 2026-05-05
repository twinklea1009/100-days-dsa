/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps. */
#include <stdio.h>
#include <stdlib.h>

// initialize table
void init(int table[], int m)
{
    for (int i = 0; i < m; i++)
    {
        table[i] = -1;
    }
}

// hash function
int hash(int key, int m)
{
    return key % m;
}

// insert using quadratic probing
void insert(int table[], int key, int m)
{
    int h = hash(key, m);

    for (int i = 0; i < m; i++)
    {
        int idx = (h + i * i) % m;

        if (table[idx] == -1)
        {
            table[idx] = key;
            return;
        }
    }
}

// search using quadratic probing
void search(int table[], int key, int m)
{
    int h = hash(key, m);

    for (int i = 0; i < m; i++)
    {
        int idx = (h + i * i) % m;

        if (table[idx] == -1)
        {
            printf("NOT FOUND\n");
            return;
        }

        if (table[idx] == key)
        {
            printf("FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main()
{
    int m, q;
    scanf("%d", &m); // table size
    scanf("%d", &q); // operations

    int *table = (int *)malloc(m * sizeof(int));

    init(table, m);

    char op[10];
    int key;

    for (int i = 0; i < q; i++)
    {
        scanf("%s %d", op, &key);

        if (op[0] == 'I')
        {
            insert(table, key, m);
        }
        else if (op[0] == 'S')
        {
            search(table, key, m);
        }
    }

    free(table);
    return 0;
}