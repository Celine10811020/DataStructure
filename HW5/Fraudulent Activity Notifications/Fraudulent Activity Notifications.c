#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int notice(int date, int mid, int even);

int expenditure[200000];
int expenditureNum[201] = {};

int main()
{
    int i, temp;
    int num, day;
    int even, mid;
    int start;
    int ans;

    scanf("%d", &num);
    scanf("%d", &day);

    for(i=0; i<num; i++)
    {
        scanf("%d", &expenditure[i]);
    }

    if(day%2 == 0)
    {
        even = 1;
    }else
    {
        even = 0;
    }

    mid = day/2;
    start = 0;
    ans = 0;

    if(num > day)
    {
        for(i=0; i<day; i++)
        {
            temp = expenditure[i];
            expenditureNum[temp]++;
        }

        for(i=day; i<num; i++)
        {
            ans = ans + notice(i, mid, even);

            if(i<num)
            {
                temp = expenditure[start];
                expenditureNum[temp]--;

                temp = expenditure[i];
                expenditureNum[temp]++;
            }

            start++;
        }
    }

    printf("%d\n", ans);

    return 0;
}

int notice(int day, int mid, int even)
{
    int i;
    int count, midium;

    count = 0;
    midium = 0;

    for(i=0; i<=200; i++)
    {
        if(expenditureNum[i]>0)
        {
            count = count + expenditureNum[i];

            if(count >= mid+1)
            {
                if(midium == 0)
                {
                    midium = i * 2;
                }else
                {
                    midium = midium + i;
                }

                break;

            }else if(even==1 && count>=mid)
            {
                midium = i;
            }
        }
    }

    if(expenditure[day] >= midium)
    {
        return 1;
    }else
    {
        return 0;
    }
}
