#include <stdio.h>

int findLength(int num);
int max(int one, int two);

int main()
{
    int i;
    int one, two;
    int length, ans;

    while(scanf("%d", &one) != EOF)
    {
        scanf("%d", &two);

        ans = 0;

        if(one == two)
        {
            ans = findLength(one);

        }else if(one < two)
        {
            for(i=one; i<=two; i++)
            {
                length = findLength(i);

                ans = max(ans, length);
            }
        }else
        {
            for(i=two; i<=one; i++)
            {
                length = findLength(i);

                ans = max(ans, length);
            }
        }

        printf("%d %d %d\n", one, two, ans);
    }

    return 0;
}

int findLength(int num)
{
    if(num == 1)
    {
        return 1;
    }else if(num%2 == 0)
    {
        return findLength(num/2) + 1;
    }else
    {
        return findLength(3*num + 1) + 1;
    }
}

int max(int one, int two)
{
    if(one > two)
    {
        return one;
    }else
    {
        return two;
    }
}
