#include <stdio.h>

int sudoku[81];

int main()
{
    int i, j;
    int valid;
    char temp;

    i = 0;
    while(i<81)
    {
        scanf("%c", &temp);

        if(temp == 120)
        {
            sudoku[i] = 0;

            i++;
        }else if(temp>=49 && temp<=57)
        {
            sudoku[i] = temp - 48;

            i++;
        }
    }

    valid = 1;

    for(i=0; i<81; i++)
    {
        for(j=0; j<81; j++)
        {
            if(i/9==j/9 && i!=j)
            {
                if(sudoku[i]==sudoku[j] && sudoku[i]!=0)
                {
                    valid = 0;
                }
            }
        }
    }

    for(i=0; i<81; i++)
    {
        for(j=0; j<81; j++)
        {
            if(i%9==j%9 && i!=j)
            {
                if(sudoku[i]==sudoku[j] && sudoku[i]!=0)
                {
                    valid = 0;
                }
            }
        }
    }

    for(i=0; i<81; i++)
    {
        for(j=0; j<81; j++)
        {
            if(((i%9)/3 == (j%9)/3) && i/27==j/27 && i!=j)
            {
                if(sudoku[i]==sudoku[j] && sudoku[i]!=0)
                {
                    valid = 0;
                }
            }
        }
    }

    if(valid)
    {
        printf("true\n");
    }else
    {
        printf("false\n");
    }

    return 0;
}
