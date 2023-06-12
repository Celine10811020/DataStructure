#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int repeat[100000] = {};
char dna[100000];
char sequence[100000][11];
int sortSequence[100000];

int main()
{
    int i, j, temp;
    int length, num;
    int found, compare, index;
    char substring[11];

    scanf("%s", dna);

    length = strlen(dna);

    if(length < 10)
    {
        printf("none\n");
    }else
    {
        num = 0;

        for(i=0; i<=length-10; i++)
        {
            for(j=0; j<10; j++)
            {
                substring[j] = dna[j+i];
            }
            substring[10] = '\0';

            found = 0;

            for(j=0; j<num; j++)
            {
                compare = strcmp(substring, sequence[j]);

                if(compare == 0)
                {
                    repeat[j] = 1;
                    found = 1;

                    break;
                }
            }

            if(found == 0)
            {
                for(j=0; j<10; j++)
                {
                    sequence[num][j] = substring[j];
                }
                sequence[num][10] = '\0';

                repeat[num] = 0;
                num++;
            }
        }

        found = 0;
        index = 0;
        for(i=0; i<num; i++)
        {
            if(repeat[i] == 1)
            {
                for(j=index-1; j>=0; j--)
                {
                    temp = sortSequence[j];

                    compare = strcmp(sequence[i], sequence[temp]);

                    if(compare < 0)
                    {
                        sortSequence[j+1] = sortSequence[j];
                    }else
                    {
                        sortSequence[j+1] = i;

                        break;
                    }
                }

                found = 1;
                index++;
            }
        }

        if(found == 0)
        {
            printf("none\n");
        }else
        {
            for(i=0; i<index; i++)
            {
                temp = sortSequence[i];

                printf("%s\n", sequence[temp]);
            }
        }
    }

    return 0;
}

