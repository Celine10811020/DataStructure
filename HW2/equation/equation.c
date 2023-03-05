#include <stdio.h>
#include <string.h>

char equation[300];
int ans[10];

int main()
{
    int i, temp;
    char tmp;
    int num;
    int index, equal, wei, impossible;
    int variable, constant;

    scanf("%d", &num);
    scanf("%c", &tmp);
    scanf("%c", &tmp);

    for(i=0; i<num; i++)
    {
        index = 0;
        equal = 0;

        while(1)
        {
            scanf("%c", &tmp);

            if(tmp == 13)
            {
                scanf("%c", &tmp);
                break;
            }

            if(tmp == 61)
            {
                equal = 1;

                equation[index] = 45;
                index++;

                continue;
            }

            if(tmp>=48 && tmp<=57)
            {
                equation[index] = tmp - 48;
            }else
            {
                if(tmp==120 && (equation[index-1]>10 || index-1<0))
                {
                    equation[index] = 1;
                    index++;
                    equation[index] = tmp;
                }else if(tmp == 120)
                {
                    equation[index] = tmp;
                }else if(equal)
                {
                    if(tmp == 43)
                    {
                        equation[index] = 45;
                    }else if(tmp == 45)
                    {
                        equation[index] = 43;
                    }
                }else
                {
                    equation[index] = tmp;
                }
            }

            index++;
        }

        index--;
        variable = 0;
        constant = 0;
        impossible = 0;

        while(index >= 0)
        {
            if(equation[index] == 120)
            {
                impossible = 1;

                index--;
                temp = 0;
                wei = 1;

                while(index>=0 && equation[index]!=43 && equation[index]!=45)
                {
                    if(equation[index] != 0)
                    {
                        temp = temp + equation[index]*wei;
                    }

                    index--;
                    wei = wei * 10;
                }

                if(equation[index] == 45)
                {
                    variable = variable - temp;
                }else
                {
                    variable = variable + temp;
                }

                index--;
            }else
            {
                temp = 0;
                wei = 1;

                while(index>=0 && equation[index]!=43 && equation[index]!=45)
                {
                    if(equation[index] != 0)
                    {
                        temp = temp + equation[index]*wei;
                    }

                    index--;
                    wei = wei * 10;
                }

                if(equation[index] == 45)
                {
                    constant = constant - temp;
                }else
                {
                    constant = constant + temp;
                }

                index--;
            }
        }

        if(variable==0 && constant==0)
        {
            ans[i] = 2147483647;
        }else if(variable==0 && constant!=0)
        {
            ans[i] = 2147483646;
        }else
        {
            ans[i] = constant / (variable * -1);

            if(ans[i]<0 && (constant%variable!=0))
            {
                ans[i]--;
            }
        }
    }

    for(i=0; i<num; i++)
    {
        if(ans[i] == 2147483647)
        {
            printf("IDENTITY\n");
        }else if(ans[i] == 2147483646)
        {
            printf("IMPOSSIBLE\n");
        }else
        {
            printf("%d\n", ans[i]);
        }
    }

    return 0;
}
