#include <stdio.h>
#include <stdlib.h>

void merge(int head, int mid, int tail);
void mergeSort(int head, int tail);

int ans;
int number[500000];

int main()
{
    int i;
    int num;

    while(1)
    {
        scanf("%d", &num);

        if(num == 0)
        {
            break;
        }

        for(i=0; i<num; i++)
        {
            scanf("%d", &number[i]);
        }

        ans = 0;

        mergeSort(0, num-1);

        printf("%d\n", ans);
    }

    return 0;
}

void merge(int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - mid;

    int *leftSub = (int*)malloc(sizeof(int)*(lenA+1));
    int *rightSub = (int*)malloc(sizeof(int)*(lenB+1));

    int leftIndex, rightIndex, writePointer;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSub[leftIndex] = number[leftIndex + head];
    }
    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSub[rightIndex] = number[rightIndex + mid + 1];
    }

    leftSub[lenA] = 2147483647;
    rightSub[lenB] = 2147483647;

    leftIndex = 0;
    rightIndex = 0;

    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        if(leftSub[leftIndex] <= rightSub[rightIndex])
        {
            number[writePointer] = leftSub[leftIndex];
            leftIndex++;
        }else
        {
            number[writePointer] = rightSub[rightIndex];
            rightIndex++;

            ans = ans + lenA - leftIndex;
        }
    }

    free(leftSub);
    free(rightSub);
}

void mergeSort(int head, int tail)
{
    int mid;

    if(head < tail)
    {
        mid = (tail+head) / 2;

        mergeSort(head, mid);
        mergeSort(mid+1, tail);
        merge(head, mid, tail);
    }
}
