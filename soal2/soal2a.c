#include <stdio.h>
// #include <string.h>
// #include <pthread.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/ipc.h>

int matrix_4x3[4][3], matrix_3x6[3][6], res[4][6];
int i, j, k;

int main()
{
    printf("Enter elemets of matrix 4x3:\n");
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d", &matrix_4x3[i][j]);
        }
    }

    printf("Enter elements of matrix 3x6:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 6; j++)
        {
            scanf("%d", &matrix_3x6[i][j]);
        }
    }

    for(i = 0; i < 4; ++i)
    {
        for(j = 0; j < 6; ++j)
        {
            res[i][j] = 0;
        }
    }

    for(i = 0; i < 4; ++i)
    {
        for(j = 0; j < 6; ++j)
        {
            for(k = 0; k < 3; ++k)
            {
                res[i][j] += matrix_4x3[i][k] * matrix_3x6[k][j];
            }
        }
    }

    printf("\n");

    return 0;
}