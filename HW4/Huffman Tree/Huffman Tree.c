#include <stdio.h>

void merge(int head, int mid, int tail);
void firstSort(int head, int tail);
void secondSort(int start, int end);

int message[100][3];
int sum[100];
int indexArr[100][2];

int main()
{
    int i, j, temp, tmp, tp;
    int index, length;
    int label;
    int ansOne, ansTwo;
    char character;

    index = 0;
    length = 0;

    while(1)
    {
        scanf("%c", &character);

        if(character == 35)
        {
            break;
        }

        i = 0;
        while(1)
        {
            if(i == index)
            {
                message[i][0] = character;
                message[i][1]++;
                index++;

                break;
            }

            if(message[i][0] == character)
            {
                message[i][1]++;
                break;
            }

            i++;
        }

        length++;
    }

    for(i=0; i<index; i++)
    {
        sum[i] = message[i][1];
        message[i][2] = 0;
        indexArr[i][0] = i;
        indexArr[i][1] = 0;
    }

    firstSort(0, index-1);

    i = 0;
    label = 1;
    while(1)
    {
        if(i == index-1)
        {
            break;
        }

        sum[i+1] = sum[i] + sum[i+1];

        if(indexArr[i][1]==0 && indexArr[i+1][1]==0)
        {
            temp = indexArr[i][0];
            message[temp][2]++;
            indexArr[i][1] = label;

            temp = indexArr[i+1][0];
            message[temp][2]++;
            indexArr[i+1][1] = label;

            label++;

        }else if(indexArr[i][1]==0)
        {
            temp = indexArr[i+1][1];

            for(j=0; j<index; j++)
            {
                if(indexArr[j][1] == temp)
                {
                    tmp = indexArr[j][0];
                    message[tmp][2]++;
                }
            }

            temp = indexArr[i][0];
            message[temp][2]++;
            indexArr[i][1] = indexArr[i+1][1];

        }else if(indexArr[i+1][1]==0)
        {
            temp = indexArr[i][1];

            for(j=0; j<index; j++)
            {
                if(indexArr[j][1] == temp)
                {
                    tmp = indexArr[j][0];
                    message[tmp][2]++;
                }
            }

            temp = indexArr[i+1][0];
            message[temp][2]++;
            indexArr[i+1][1] = indexArr[i][1];
        }else
        {
            temp = indexArr[i][1];

            for(j=0; j<index; j++)
            {
                if(indexArr[j][1] == temp)
                {
                    tmp = indexArr[j][0];
                    message[tmp][2]++;
                }
            }

            tmp = indexArr[i+1][1];

            for(j=0; j<index; j++)
            {
                if(indexArr[j][1] == tmp)
                {
                    tp = indexArr[j][0];
                    message[tp][2]++;

                    indexArr[j][1] = temp;
                }
            }
        }

        secondSort(i+1, index);

        i++;
    }

    ansOne = 0;
    ansTwo = 0;
    for(i=0; i<index; i++)
    {
        ansOne = ansOne + message[i][1] * message[i][2];
        ansTwo = ansTwo + message[i][1];
    }
    ansTwo = ansTwo * 8;

    printf("%d / %d\n", ansOne, ansTwo);

    return 0;
}

void firstSort(int head, int tail)
{
    int mid=0;
    if(head < tail)
    {
        mid = (head+tail) / 2;
        firstSort(head, mid);
        firstSort(mid+1, tail);
        merge(head, mid, tail);
    }
}

int leftSubChar[50];
int leftSubIndex[50];
int rightSubChar[50];
int rightSubIndex[50];

void merge(int head, int mid, int tail)
{
    int lenA = mid - head + 1;
    int lenB = tail - (mid+1) + 1;

    int leftIndex = 0;
    int rightIndex = 0;

    for(leftIndex=0; leftIndex<lenA; leftIndex++)
    {
        leftSubChar[leftIndex] = sum[head + leftIndex];
        leftSubIndex[leftIndex] = indexArr[head + leftIndex][0];
    }

    for(rightIndex=0; rightIndex<lenB; rightIndex++)
    {
        rightSubChar[rightIndex] = sum[mid + 1 + rightIndex];
        rightSubIndex[rightIndex] = indexArr[mid + 1 + rightIndex][0];
    }

    leftSubChar[lenA] = 2147483647;
    rightSubChar[lenB] = 2147483647;

    leftIndex = 0;
    rightIndex = 0;

    int writePointer=0;
    for(writePointer=head; writePointer<=tail; writePointer++)
    {
        if(leftSubChar[leftIndex] <= rightSubChar[rightIndex])
        {
            sum[writePointer] = leftSubChar[leftIndex];
            indexArr[writePointer][0] = leftSubIndex[leftIndex++];
        }else
        {
            sum[writePointer] = rightSubChar[rightIndex];
            indexArr[writePointer][0] = rightSubIndex[rightIndex++];
        }
    }
}

void secondSort(int start, int end)
{
    int i;
    int tempOne, tempTwo, tempThree;

    tempOne = sum[start];
    tempTwo = indexArr[start][0];
    tempThree = indexArr[start][1];

    for(i=start+1; i<end; i++)
    {
        if(tempOne > sum[i])
        {
            sum[i-1] = sum[i];
            indexArr[i-1][0] = indexArr[i][0];
            indexArr[i-1][1] = indexArr[i][1];
        }else
        {
            sum[i-1] = tempOne;
            indexArr[i-1][0] = tempTwo;
            indexArr[i-1][1] = tempThree;

            return;
        }
    }

    sum[end-1] = tempOne;
    indexArr[end-1][0] = tempTwo;
    indexArr[end-1][1] = tempThree;

    return;
}
