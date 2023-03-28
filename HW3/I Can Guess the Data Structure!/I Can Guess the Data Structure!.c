#include <stdio.h>

int findMax();

int stack[1000];
int queue[1000];
int max[101];
int structure[3]; //0: stack, 1: queue, 2: max

int main()
{
    int i;
    int num, one, two;
    int pushS, pushQ, popS, popQ;

    while(scanf("%d", &num) != EOF)
    {
        pushS = 0;
        pushQ = 0;
        popS = -1;
        popQ = 0;
        structure[0] = 1;
        structure[1] = 1;
        structure[2] = 1;

        for(i=1; i<=100; i++)
        {
            max[i] = 0;
        }

        for(i=0; i<num; i++)
        {
            scanf("%d", &one);
            scanf("%d", &two);

            if(one == 1)
            {
                stack[pushS] = two;
                queue[pushQ] = two;
                max[two]++;

                pushS++;
                pushQ++;
                popS++;
            }else
            {
                if(stack[popS] != two)
                {
                    structure[0] = 0;
                }
                if(queue[popQ] != two)
                {
                    structure[1] = 0;
                }
                if(findMax() != two)
                {
                    structure[2] = 0;
                }

                pushS--;
                popS--;
                popQ++;
                max[two]--;
            }
        }

        if(structure[0]==0 && structure[1]==0 && structure[2]==0)
        {
            printf("impossible\n");
        }else if(structure[0]==1 && structure[1]==0 && structure[2]==0)
        {
            printf("stack\n");
        }else if(structure[0]==0 && structure[1]==1 && structure[2]==0)
        {
            printf("queue\n");
        }else if(structure[0]==0 && structure[1]==0 && structure[2]==1)
        {
            printf("priority queue\n");
        }else
        {
            printf("not sure\n");
        }
    }

    return 0;
}

int findMax()
{
    int i;

    for(i=100; i>0; i--)
    {
        if(max[i] > 0)
        {
            return i;
        }
    }

    return 0;
}
