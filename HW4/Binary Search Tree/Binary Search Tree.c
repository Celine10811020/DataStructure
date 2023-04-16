#include <stdio.h>

void add(int num);
void search(int num);
int delet(int num);
int leaf(int index);
int findMax(int index);
int findMin(int index);

int tree[3000];

int main()
{
    int temp;
    char string[10];

    while(scanf("%s", string) != EOF)
    {
        scanf("%d", &temp);

        if(string[0] == 'a')
        {
            add(temp);
        }else if(string[0] == 's')
        {
            search(temp);
        }else
        {
            temp = delet(temp);

            if(temp == 0)
            {
                printf("not found\n");
            }
        }
    }

    return 0;
}

void add(int num)
{
    int index;

    index = 1;

    while(1)
    {
        if(tree[index] == 0)
        {
            tree[index] = num;

            return;
        }

        if(num > tree[index])
        {
            index = 2*index + 1;
        }else
        {
            index = 2*index;
        }
    }
}

void search(int num)
{
    int index;

    index = 1;

    while(1)
    {
        if(tree[index] == 0)
        {
            printf("not found\n");

            return;
        }

        if(num > tree[index])
        {
            printf("%d ", tree[index]);

            index = 2*index + 1;

        }else if(num < tree[index])
        {
            printf("%d ", tree[index]);

            index = 2*index;
        }else
        {
            printf("%d\n", tree[index]);

            return;
        }
    }
}

int delet(int num)
{
    int index, temp;

    index = 1;

    while(1)
    {
        if(tree[index] == 0)
        {
            return 0;
        }

        if(num > tree[index])
        {
            index = 2*index + 1;

        }else if(num < tree[index])
        {
            index = 2*index;
        }else
        {
            temp = leaf(index);

            if(temp == 1)
            {
                tree[index] = 0;
            }else if(temp == 2)
            {
                temp = findMax(2*index);
                tree[index] = tree[temp];

                while(1)
                {
                    index = temp;

                    if(tree[2*index] == 0)
                    {
                        tree[index] = 0;

                        break;
                    }

                    temp = findMax(2*index);
                    tree[index] = tree[temp];
                }
            }else
            {
                temp = findMin(2*index+1);
                tree[index] = tree[temp];

                while(1)
                {
                    index = temp;

                    if(tree[2*index+1] == 0)
                    {
                        tree[index] = 0;

                        break;
                    }

                    temp = findMin(2*index+1);
                    tree[index] = tree[temp];
                }
            }

            return 1;
        }
    }
}

int leaf(int index)
{
    if(tree[2*index] == 0 && tree[2*index+1] == 0)
    {
        return 1;
    }else if(tree[2*index+1] == 0)
    {
        return 2;
    }else
    {
        return 3;
    }
}

int findMax(int index)
{
    while(1)
    {
        if(tree[2*index+1] == 0)
        {
            return index;
        }

        index = 2*index + 1;
    }
}

int findMin(int index)
{
    while(1)
    {
        if(tree[2*index] == 0)
        {
            return index;
        }

        index = 2*index;
    }
}
