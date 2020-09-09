#include <stdio.h>
#define SIZE 4

int BF(int src, int dst, int A[SIZE][SIZE])
{
    int visible[SIZE];
    int updated; // a flag for earlier return

    for (int i = 0; i < SIZE; i++)
    {
        visible[i] = 0x7fffffff;
    }
    visible[src] = 0;

    // we need at most SIZE-1 iterations
    for (int k = 0; k < SIZE - 1; k++)
    {

        updated = 0;

        // for each visible node if we see a shorter path to it's neighbors, update.
        for (int i = 0; i < SIZE; i++)
        {
            if (visible[i] == 0x7fffffff)
                continue;

            for (int j = 0; j < SIZE; j++)
            {
                if (A[i][j] > 0 && (visible[i] + A[i][j]) < visible[j])
                {
                    visible[j] = visible[i] + A[i][j];
                    updated = 1;
                }
            }
        }

        // if we don't see any improvement, we can exit earlier
        if (updated == 0)
            break;
    }

    return visible[dst];
}

int main()
{

    int A[SIZE][SIZE] = {{0, 4, 2, 7},
                         {1, 0, 5, 0},
                         {2, 0, 0, 4},
                         {0, 3, 0, 0}};
    printf("%d\n", BF(1, 3, A));
}