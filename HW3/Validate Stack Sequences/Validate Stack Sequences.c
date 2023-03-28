#include <stdio.h>

int input[1000];
int output[1000];
int stack[1000];

int main()
{
    int i;
    int num;
    int pointer, indexIn, indexOut;
    int ans;

    while(scanf("%d", &num) != EOF)
    {
        for(i=0; i<num; i++)
        {
            scanf("%d", &input[i]);
        }
        for(i=0; i<num; i++)
        {
            scanf("%d", &output[i]);
        }

        pointer = 0;
        indexIn = 0;
        indexOut = 0;
        ans = 1;

        while(1)
        {
            if(pointer == 0)
            {
                stack[pointer] = input[indexIn];

                indexIn++;
                pointer++;
            }else
            {
                if(stack[pointer-1] == output[indexOut])
                {
                    pointer--;
                    indexOut++;
                }else
                {
                    if(indexIn < num)
                    {
                        stack[pointer] = input[indexIn];

                        indexIn++;
                        pointer++;
                    }else
                    {
                        ans = 0;
                        break;
                    }
                }
            }

            if(indexOut==num)
            {
                break;
            }
        }

        if(ans)
        {
            printf("true\n");
        }else
        {
            printf("false\n");
        }
    }

    return 0;
}
