#include <stdio.h>

int symmetric(int num);

long long matrix[200][200];

int main()
{
    int i, j, k;
    int matrixNum, num;
    char temp, test;

    scanf("%d", &matrixNum);

    for(i=0; i<matrixNum; i++)
    {
        for(j=0; j<6; j++)
        {
            scanf("%c", &temp);
        }

        scanf("%d", &num);

        for(j=0; j<num; j++)
        {
            for(k=0; k<num; k++)
            {
                scanf("%lld", &matrix[j][k]);
            }
        }

        test = symmetric(num);

        if(test == 1)
        {
            printf("Test #%d: Symmetric.\n", i+1);
        }else
        {
            printf("Test #%d: Non-symmetric.\n", i+1);
        }
    }

    return 0;
}

int symmetric(int num)
{
    int i, j;

    for(i=0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            if(matrix[i][j] < 0)
            {
                return 0;
            }else if(matrix[i][j] != matrix[num-i-1][num-j-1])
            {
                return 0;
            }
        }
    }

    return 1;
}
