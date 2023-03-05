#include <stdio.h>

int array[10000];

int main()
{
    int i;
    int num;
    int test;

    while(scanf("%d", &num) != EOF)
    {
        test = 0;

        for(i=0; i<num; i++)
        {
            scanf("%d", &array[i]);
        }

        for(i=1; i<num; i++)
        {
            if(array[i-1] > array[i])
            {
                if(test == 1)
                {
                    test = 2;
                    break;
                }

                if(array[i+1]>=array[i-1] && i-1<num)
                {
                    test = 1;
                }else if(array[i]>=array[i-2] && i-2>=0)
                {
                    test = 1;
                }else
                {
                    test = 2;
                    break;
                }
            }
        }


        if(test == 2)
        {
            printf("false\n");
        }else
        {
            printf("true\n");
        }
    }


    return 0;
}
