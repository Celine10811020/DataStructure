#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    int x, y;
    int one, two;
    char direction;
    char instruction[100];
    int length;
    char danger[50][50] = {};
    int lost;

    scanf("%d", &x);
    scanf("%d", &y);

    while(scanf("%d", &one) != EOF)
    {
        scanf("%d", &two);
        scanf("%c", &direction);
        scanf("%c", &direction);
        scanf("%s", instruction);

        length = strlen(instruction);

        lost = 0;
        for(i=0; i<length; i++)
        {
            if(instruction[i] == 'F')
            {
                //printf("\t%d %d %c %c\n", one, two, danger[one][two], direction);
                if(danger[one][two] == direction)
                {
                    continue;
                }

                if(direction == 'N')
                {
                    two++;

                    if(two > y)
                    {
                        two--;

                        danger[one][two] = direction;

                        lost = 1;

                        break;
                    }
                }else if(direction == 'E')
                {
                    one++;

                    if(one > x)
                    {
                        one--;

                        danger[one][two] = direction;

                        lost = 1;

                        break;
                    }
                }else if(direction == 'S')
                {
                    two--;

                    if(two < 0)
                    {
                        two++;

                        danger[one][two] = direction;

                        lost = 1;

                        break;
                    }
                }else
                {
                    one--;

                    if(one < 0)
                    {
                        one++;

                        danger[one][two] = direction;

                        lost = 1;

                        break;
                    }
                }
            }else if(instruction[i] == 'R')
            {
                if(direction == 'N')
                {
                    direction = 'E';
                }else if(direction == 'E')
                {
                    direction = 'S';
                }else if(direction == 'S')
                {
                    direction = 'W';
                }else
                {
                    direction = 'N';
                }
            }else
            {
                if(direction == 'N')
                {
                    direction = 'W';
                }else if(direction == 'E')
                {
                    direction = 'N';
                }else if(direction == 'S')
                {
                    direction = 'E';
                }else
                {
                    direction = 'S';
                }
            }
        }

        if(lost == 0)
        {
            printf("%d %d %c\n", one, two, direction);
        }else
        {
            printf("%d %d %c LOST\n", one, two, direction);
        }
    }

    return 0;
}
