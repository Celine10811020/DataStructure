#include <stdio.h>

long long root[60];
long long coefficient[60];

int main()
{
    int i, j, temp;
    int num;
    int sign;

    temp = 1;

    while(scanf("%d", &num) != EOF)
    {
        for(i=0; i<num; i++)
        {
            scanf("%lld", &root[i]);
            coefficient[i] = 0;

            if(root[i] != 0)
            {
                temp = 0;
            }
        }

        if(temp)
        {
            printf("0 = 0\n");
            continue;
        }

        coefficient[num] = 1;

        for(i=num-1; i>=0; i--)
        {
            for(j=i-1; j<num; j++)
            {
                //printf("\t%d + %d * %d", coefficient[j], coefficient[j+1], root[i]);
                coefficient[j] = coefficient[j] + coefficient[j+1]*root[i];
                //printf(" = %d\t(%d, %d)\n", coefficient[j], i, j);
            }
        }

        //debug
        /*printf("\n\t");
        for(i=num; i>=0; i--)
        {
            printf("%d ", coefficient[i]);
        }
        printf("\n");*/

        sign = 0;

        for(i=num; i>=0; i--)
        {
            if(i == 0)
            {
                printf("%lld = 0\n", coefficient[i]);
            }else
            {
                if(coefficient[i] == 0)
                {
                    continue;
                }else if(coefficient[i]!=1 && coefficient[i]!=-1)
                {
                    printf("%lld", coefficient[i]);
                }

                if(i == 1)
                {
                    printf("x ");
                }else
                {
                    printf("x^%d ", i);
                }

                if(sign)
                {
                    if(coefficient[i-1] >= 0)
                    {
                        printf("+ ");
                    }else
                    {
                        printf("- ");

                        coefficient[i-1] = coefficient[i-1] * -1;
                    }

                    sign = 0;
                }else
                {
                    if(coefficient[i-1] > 0)
                    {
                        printf("- ");
                    }else
                    {
                        printf("+ ");

                        coefficient[i-1] = coefficient[i-1] * -1;
                    }

                    sign = 1;
                }
            }
        }
    }


    return 0;
}
